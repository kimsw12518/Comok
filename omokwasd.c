#include<stdio.h>
#include<stdlib.h>
#include<windows.h> 

void display(int map[15][15],int player,int last,int now);
int coord(char inp,int now);
int game(int map[15][15]);


int main()
{
	system("color f0");
	int i,j,map[15][15]={{0,},},player=0,end=0,a=112,last=112,p,now=112;
	char inp;
	map[7][7]=player+1;
	for(player=1;end==0;player=(player+1)%2){
		while(1){
			p=game(map);
			display(map,player,last,now);
			if(p!=0){
				printf("Player %d wins!",p);
				break;
			}
			inp=getch();
			a=coord(inp,now);
			now=(now+a+225)%225;
			if(a==225){
				if(map[now%15][now/15]==0){
					map[now%15][now/15]=player+1;
					last=now;
					break;
				}
			}
		}
		if(p!=0){
				break;
			}
	}
}


void display(int map[15][15],int player,int last,int now)
{
	int i,j;
	system("cls");
	if(player==0) printf("\n     Player: ●\t\t    Last: ");
	else printf("\n     Player: ○\t\t    Last: ");
	printf("%c%d",(last/15)+'A',last%15+1);
	printf("\n\n\tＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯ");
	for(i=0;i<15;i++){
		printf("\n     %d\t",i+1); 
		for(j=0;j<15;j++){
			if(map[i][j]==1){
				if(i==now%15&&j==now/15){
					printf("■");
				} 
				else{
					printf("●");
				}
			}
			
			else if(map[i][j]==2){
				if(i==now%15&&j==now/15){
					printf("□");
				} 
				else{
					printf("○");
				}
			}
			else{
				if(i==now%15&&j==now/15){
					printf("◎");
				} 
				else{
					switch(i){
						case 0:switch(j){
							case 0:printf("┏ ");break;
							case 14:printf("┓");break;
							default:printf("┳ ");break;
						}break; 
						case 14:switch(j){
							case 0:printf("┗ ");break;
							case 14:printf("┛");break;
							default:printf("┻ ");break;
						}break;
						default:switch(j){
							case 0:printf("┣ ");break;
							case 14:printf("┫");break;
							default:printf("╋ ");break;
						}break;
					}
				}
			} 
		}
	}
	printf("\n\n");
} 

int coord(char inp,int now)
{
	
	if(inp=='w'){
		if(now%15==0) return 14;
		else return -1;
	}
	if(inp=='a'){
		return -15;
	}
	if(inp=='s'){
		if(now%15==14) return -14;
		else return 1;
	}
	if(inp=='d'){
		return 15;
	}
	if(inp==' '){
		return 225;
	}
	return 0;
}

int game(int map[15][15]) //대각선 안만듬 
{
	int count[6][2]={{1,0},{1,0},{1,0},{1,0},{1,0},{1,0}},i,j,k,l;
	for(i=0;i<15;i++){
		for(l=0;l<6;l++){
			count[l][0]=1;
			count[l][1]=0;
		}
		for(j=0;j<15;j++){
			if(map[i][j]==count[0][1]&&count[0][1]!=0){
				count[0][0]++;
				if(count[0][0]>4){
					return count[0][1];
				}
			}
			else{
				count[0][0]=1;
				count[0][1]=map[i][j];
			}
			if(map[j][i]==count[1][1]&&count[1][1]!=0){
				count[1][0]++;
				if(count[1][0]>4){
					return count[1][1];
				}
			}
			else{
				count[1][0]=1;
				count[1][1]=map[j][i];
			}
		}
		for(k=0;k<i+1;k++){
			if(map[i-k][k]==count[2][1]&&count[2][1]!=0){
				count[2][0]++;
				if(count[2][0]>4){
					return count[2][1];
				}
			}
			else{
				count[2][0]=1;
				count[2][1]=map[i-k][k];
			}
			if(map[14-(i-k)][14-k]==count[3][1]&&count[3][1]!=0){
				count[3][0]++;
				if(count[3][0]>4){
					return count[3][1];
				}
			}
			else{
				count[3][0]=1;
				count[3][1]=map[14-(i-k)][14-k];
			}
			if(map[i-k][14-k]==count[4][1]&&count[4][1]!=0){
				count[4][0]++;
				if(count[4][0]>4){
					return count[4][1];
				}
			}
			else{
				count[4][0]=1;
				count[4][1]=map[i-k][14-k];
			}
			if(map[14-(i-k)][k]==count[5][1]&&count[5][1]!=0){
				count[5][0]++;
				if(count[5][0]>4){
					return count[5][1];
				}
			}
			else{
				count[5][0]=1;
				count[5][1]=map[14-(i-k)][14-k];
			}
		}
	}
	return 0;
}
