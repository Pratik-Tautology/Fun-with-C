#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void append(int A[6][2],int a,int b);
int Abs(int a,int b);
int win(char A[3][3]);
int empty(char A[3][3]);
int win_player_2(char A[3][3]);
int win_player_1(char A[3][3]);
int chances(char A[3][3]);
int game_end(char A[3][3]);
int last_element(int A[6][2]);
void print(char A[3][3]);



// 1 is for player 1    ;    player 1  always plays first
// 0 is for player 2


int g_p,g_q;
main(){
	srand(time(NULL));
	// P_1 2D array stores coordinate in same order as player 1 plays
	// p_2 2D array stores coordinate in same order as player 2 plays
	int P_1[6][2];
	int P_2[6][2];
	int i,j,k,x,y;
	P_1[0][0]=-1;
	P_1[0][1]=-1;
	P_2[0][0]=-1;
	P_2[0][1]=-1;
	char A[3][3];

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		A[i][j]='_';
		}
	}
	printf("1,1 1,2 1,3\n2,1 2,2 2,3\n3,1 3,2 3,3\n");
	print(A);
	printf("**********************************************************\n");
	int ra=rand()%2;
	int rb=rand()%2;
	if(ra==1)
		ra=2;
	if(rb==1)
		rb=2;
	A[ra][rb]='1';
	int p1=ra,q1=rb;
	append(P_1,p1,q1);
	print(A);
	int p2,q2;
	printf("Player 2 coordinates : ");
	scanf("%d %d",&p2,&q2);
	p2--;
	q2--;
	A[p2][q2]='0';
	print(A);
	append(P_2,p2,q2);
	// case I
	if( (Abs(p1,p2)==1 && Abs(q1,q2)==0) || (Abs(p1,p2)==0 && Abs(q1,q2)==1) ){
		if( p1==p2 ){
			// Means Both 1 and 0 are in same row
			if(p1==0){
				A[2][q1]='1';
				append(P_1,2,q1);
			}
			else if(p1==2){
				A[0][q1]='1';
				append(P_1,0,q1);
			}
		}
		else if(q1==q2){
			if(q1==0){
				A[p1][2]='1';
				append(P_1,p1,2);
			}
			else if(q1==2){
				A[p1][0]='1';
				append(P_1,p1,0);
			}
		}
		print(A);
		printf("Player 2 coordinates : ");
		scanf("%d %d",&p2,&q2);
		p2--;
		q2--;
		A[p2][q2]='0';
		append(P_2,p2,q2);
		print(A);
		if(win_player_1(A)==1){
			if(A[g_p][g_q]=='_'){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
				printf("Player 1 wins!!\n");
			}

			else{
				print(A);
				if(P_1[0][1]==P_1[1][1]){
					for(i=0;i<3;i++){
						if(P_2[0][1]!=i || P_2[1][1]!=i){
							if(A[0][1]=='_'){
								A[0][i]='1';
								append(P_1,0,i);
								print(A);
							}
							else if(A[2][1]=='_'){
								A[2][i]='1';
								append(P_1,2,i);
								print(A);
							}
							break;
						}
					}
				}
				else if(P_1[0][0]==P_1[1][0]){
					for(i=0;i<3;i++){
						if(P_2[0][0]!=i || P_2[1][0]!=i){
							if(A[0][1]=='_'){
								A[0][i]='1';
								append(P_1,0,i);
								print(A);
							}
							else if(A[2][0]=='_'){
								A[2][i]='1';
								append(P_1,2,i);
								print(A);
							}
						}
					}
				}

				printf("Player 2 coordinates : ");
				scanf("%d %d",&p2,&q2);
				p2--;
				q2--;
				A[p2][q2]='0';
				append(P_2,p2,q2);
				print(A);
				if(win_player_1(A)==1){
					A[g_p][g_q]='1';
					append(P_1,g_p,g_q);
					print(A);
					printf("Player 1 wins!!\n");
				}
			}
		}
	}  // case I ends here!!
	else if(Abs(p1,p2)==1 && Abs(q1,q2)==1){							// case II
		for(i=0;i<3;i++){
			k=0;
			for(j=0;j<3;j++){
				if(A[j][i]=='_')
					k++;
			}
			if(k==3)
				break;
		}
		for(x=0;x<3;x++){
			k=0;
			for(y=0;y<3;y++){
				if(A[x][y]=='_')
					k++;
			}
			if(k==3)
				break;
		}
		A[x][i]='1';
		append(P_1,x,i);
		print(A);
		printf("Player 2 coordinates : ");
		scanf("%d %d",&p2,&q2);
		p2--;
		q2--;
		A[p2][q2]='0';
		append(P_2,p2,q2);
		print(A);
		k=0;
		if(win_player_1(A)==1){
			A[g_p][g_q]='1';
			append(P_1,g_p,g_q);
			print(A);
			k=1;
			printf("Player 1 wins!!\n");
		}
		else if(win_player_2(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
		}
		if(k!=1){
		printf("Player 2 coordinates : ");
		scanf("%d %d",&p2,&q2);
		p2--;
		q2--;
		A[p2][q2]='0';
		append(P_2,p2,q2);
		print(A);
		if(win_player_1(A)==1){
			A[g_p][g_q]='1';
			append(P_1,g_p,g_q);
			print(A);
			k=1;
			printf("Player 1 wins!!\n");
		}
		else if(win_player_2(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
		}
		else{
			for(i=0;i<3;i++){
				k=0;
				for(j=0;j<3;j++){
					if(A[i][j]=='_'){
						A[i][j]='1';
						append(P_1,i,j);
						print(A);
						k=1;
						break;
					}
				}
				if(k==1)
					break;
			}

		}
		if(k!=1){
		printf("Player 2 coordinates : ");
		scanf("%d %d",&p2,&q2);
		p2--;
		q2--;
		A[p2][q2]='0';
		append(P_2,p2,q2);
		print(A);
		for(i=0;i<3;i++){
			k=0;
			for(j=0;j<3;j++){
				if(A[i][j]=='_'){
					A[i][j]='1';
					append(P_1,i,j);
					print(A);
					k=1;
					break;
				}
			}
			if(k==1)
				break;
		}
		if(game_end(A)==1)
			printf("Player 1 wins!!\n");
		else if(game_end(A)==3)
			printf("Game Draws !!\n");
		}}
	} // case II ends here!!

	// case III begins here!!
	else if(Abs(p1,p2)==2 && Abs(q1,q2)==2){
		srand(time(NULL));
		i=rand()%2;
		k=0;
		if(i==0){
			A[p1][q2]='1';
			append(P_1,p1,q2);
			print(A);
		}
		else{
			A[p2][q1]='1';
			append(P_1,p2,q1);
			print(A);
		}
		printf("Player 2 coordinates : ");
		scanf("%d %d",&p2,&q2);
		p2--;
		q2--;
		A[p2][q2]='0';
		append(P_2,p2,q2);
		print(A);
		if(win_player_1(A)==1){
			A[g_p][g_q]='1';
			append(P_1,g_p,g_q);
			print(A);
			k=1;
			printf("Player 1 wins!!\n");
		}
		else if(win_player_2(A)==1){
			A[g_p][g_q]='1';
			append(P_1,g_p,g_q);
			print(A);
		}
		else{
			if(A[P_2[0][0]][P_2[1][1]]=='_'){
				A[P_2[0][0]][P_2[1][1]]='1';
				append(P_1,P_2[0][0],P_2[1][1]);
				print(A);
			}
			else if(A[P_2[0][1]][P_2[1][0]]=='_'){
				A[P_2[0][1]][P_2[1][0]]='1';
				append(P_1,P_2[0][1],P_2[1][0]);
				print(A);
			}
		}
		if(k!=1){
		printf("Player 2 coordinates : ");
		scanf("%d %d",&p2,&q2);
		p2--;
		q2--;
		A[p2][q2]='0';
		append(P_2,p2,q2);
		print(A);
		for(i=0;i<3;i++){
				k=0;
				for(j=0;j<3;j++){
					if(A[i][j]=='_'){
						A[i][j]='1';
						append(P_1,i,j);
						print(A);
						k=1;
						break;
					}
				}
				if(k==1)
					break;
			}
		printf("Player 2 coordinates : ");
		scanf("%d %d",&p2,&q2);
		p2--;
		q2--;
		A[p2][q2]='0';
		append(P_2,p2,q2);
		print(A);
		if(win_player_1(A)==1){
			A[g_p][g_q]='1';
			append(P_1,g_p,g_q);
			print(A);
			k=1;
			printf("Player 1 wins!!\n");
		}
		else if(win_player_2(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
		}
		else{
			for(i=0;i<3;i++){
				k=0;
				for(j=0;j<3;j++){
					if(A[i][j]=='_'){
						A[i][j]='1';
						append(P_1,i,j);
						print(A);
						k=1;
						break;
					}
				}
				if(k==1)
					break;
			}
		}
		if(game_end(A)==3)
			printf("Game Draws!!\n");
	}
	} // case III ends here!!

	// case IV begins here !!
	else if(((A[0][0]=='1'||A[2][2]=='1')&&Abs(q1,q2)==2&&Abs(p1,p2)==1) || ((A[0][2]=='1'||A[2][0]=='1')&&Abs(q1,q2)==1&&Abs(p1,p2)==2)){
		k=0;
		if((A[0][0]=='1'||A[2][2]=='1')&&Abs(q1,q2)==2&&Abs(p1,p2)==1){
			A[p1][q2]='1';
			append(P_1,p1,q1);
			print(A);
		}
		else if((A[0][2]=='1'||A[2][0]=='1')&&Abs(q1,q2)==1&&Abs(p1,p2)==2){
			A[p2][q1]='1';
			append(P_1,p2,q1);
			print(A);
		}
			printf("Player 2 coordinates : ");
			scanf("%d %d",&p2,&q2);
			p2--;
			q2--;
			A[p2][q2]='0';
			append(P_2,p2,q2);
			print(A);

			if(win_player_1(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
				printf("Player 1 wins!!\n");
				k=1;
			}
			else{
				A[1][1]='1';
				append(P_1,1,1);
				print(A);
			}
			if(k!=1){
			printf("Player 2 coordinates : ");
			scanf("%d %d",&p2,&q2);
			p2--;
			q2--;
			A[p2][q2]='0';
			append(P_2,p2,q2);
			print(A);
			if(win_player_1(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
				printf("Player 1 wins!!\n");
			}

	}
	} // case IV ends here !!

	// case V begins here
	else if(((A[0][0]=='1'||A[2][2]=='1')&&Abs(q1,q2)==1&&Abs(p1,p2)==2)||((A[2][0]=='1'||A[0][2]=='1')&&Abs(q1,q2)==2&&Abs(p1,p2)==1)){
		k=0;
		A[1][1]='1';
		append(P_1,1,1);
		print(A);
		printf("Player 2 coordinates : ");
			scanf("%d %d",&p2,&q2);
			p2--;
			q2--;
			A[p2][q2]='0';
			append(P_2,p2,q2);
			print(A);

			if(win_player_1(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
				printf("Player 1 wins!!\n");
				k=1;
			}
			else if(win_player_2(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
			}
			else{
				if((A[0][0]=='1'||A[2][2]=='1')&&Abs(q1,q2)==1&&Abs(p1,p2)==2){
					A[p2][q1]='1';
					append(P_1,p2,q1);
					print(A);
				}
				else if((A[2][0]=='1'||A[0][2]=='1')&&Abs(q1,q2)==2&&Abs(p1,p2)==1){
					A[p1][q2]='1';
					append(P_1,p2,q1);
					print(A);
				}
			}
				printf("Player 2 coordinates : ");
				scanf("%d %d",&p2,&q2);
				p2--;
				q2--;
				A[p2][q2]='0';
				append(P_2,p2,q2);
				print(A);
			if(win_player_1(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
				printf("Player 1 wins!!\n");
			}


	} 	// case V ends here !!!

	// case VI begins here !!
	else if(((A[0][0]=='1'||A[2][2]=='1')&&Abs(q1,q2)==0&&Abs(p1,p2)==2)||((A[0][2]=='1'||A[2][0]=='1')&&Abs(p1,p2)==0&&Abs(q1,q2)==2)){
		A[1][1]='1';
		k=0;
		append(P_1,1,1);
		print(A);
		printf("Player 2 coordinates : ");
		scanf("%d %d",&p2,&q2);
		p2--;
		q2--;
		A[p2][q2]='0';
		append(P_2,p2,q2);
		print(A);
		if(win_player_1(A)==1){
			A[g_p][g_q]='1';
			append(P_1,g_p,g_q);
			print(A);
			k=1;
			printf("Player 1 wins!!\n");
		}
		else{
			if(win_player_2(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
			}
			printf("Player 2 coordinates : ");
			scanf("%d %d",&p2,&q2);
			p2--;
			q2--;
			A[p2][q2]='0';
			append(P_2,p2,q2);
			print(A);
			if(win_player_1(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
				k=1;
				printf("Player 1 wins!!\n");
			}
			else{
			if(win_player_2(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
			}
			else{
				for(i=0;i<3;i++){
					k=0;
					for(j=0;j<3;j++){
						if(A[i][j]=='_'){
							k=1;
							break;
						}
					}
					if(k==1)
						break;
				}
				A[i][j]='1';
				append(P_1,g_p,g_q);
				print(A);
				//**************************

				printf("Player 2 coordinates : ");
				scanf("%d %d",&p2,&q2);
				p2--;
				q2--;
				A[p2][q2]='0';
				append(P_2,p2,q2);
				print(A);
				if(win_player_1(A)==1){
					A[g_p][g_q]='1';
					append(P_1,g_p,g_q);
					print(A);
					k=1;
					printf("Player 1 wins!!\n");
				}
				else{
					for(i=0;i<3;i++){
						k=0;
						for(j=0;j<3;j++){
							if(A[i][j]=='_'){
								k=1;
								break;
							}
						}
						if(k==1)
							break;
					}
					A[i][j]='1';
					append(P_1,g_p,g_q);
					print(A);
					printf("Game Draws\n");
				}

				//*************************
			}
			}
		}
	} // case VI ends here !!

	// case VII begins here !!

	else if(((A[0][0]=='1'||A[2][2]=='1')&&Abs(q1,q2)==2&&Abs(p1,p2)==0)||((A[0][2]=='1'||A[2][0]=='1')&&Abs(q1,q2)==0&&Abs(p1,p2)==2)){
		A[1][1]='1';
		k=0;
		append(P_1,1,1);
		print(A);
		printf("Player 2 coordinates : ");
		scanf("%d %d",&p2,&q2);
		p2--;
		q2--;
		A[p2][q2]='0';
		append(P_2,p2,q2);
		print(A);
		if(win_player_1(A)==1){
			A[g_p][g_q]='1';
			append(P_1,g_p,g_q);
			print(A);
			k=1;
			printf("Player 1 wins!!\n");
		}
		else{
			if(win_player_2(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
			}
			printf("Player 2 coordinates : ");
			scanf("%d %d",&p2,&q2);
			p2--;
			q2--;
			A[p2][q2]='0';
			append(P_2,p2,q2);
			print(A);
			if(win_player_1(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
				k=1;
				printf("Player 1 wins!!\n");
			}
			else{
			if(win_player_2(A)==1){
				A[g_p][g_q]='1';
				append(P_1,g_p,g_q);
				print(A);
			}
			else{
				for(i=0;i<3;i++){
					k=0;
					for(j=0;j<3;j++){
						if(A[i][j]=='_'){
							k=1;
							break;
						}
					}
					if(k==1)
						break;
				}
				A[i][j]='1';
				append(P_1,g_p,g_q);
				print(A);
				//**************************

				printf("Player 2 coordinates : ");
				scanf("%d %d",&p2,&q2);
				p2--;
				q2--;
				A[p2][q2]='0';
				append(P_2,p2,q2);
				print(A);
				if(win_player_1(A)==1){
					A[g_p][g_q]='1';
					append(P_1,g_p,g_q);
					print(A);
					k=1;
					printf("Player 1 wins!!\n");
				}
				else{
					for(i=0;i<3;i++){
						k=0;
						for(j=0;j<3;j++){
							if(A[i][j]=='_'){
								k=1;
								break;
							}
						}
						if(k==1)
							break;
					}
					A[i][j]='1';
					append(P_1,g_p,g_q);
					print(A);
					printf("Game Draws\n");
				}

				//*************************
			}
			}
		}




	}



}  // main end here !!

void print(char A[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%c  ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}



int last_element(int A[6][2]){
	int i=0;
	while(A[i][0]!=-1)
		i++;
	i--;
	return i;
}


int Abs(int a,int b){
	if(a>b)
		return a-b;
	return b-a;
}
int game_end(char A[3][3]){
	// returns 1 if player 1 wins
	// returns 2 if player 2 wins
	// returns 3 if game is a draw
	// returns 0 if game is not the end
	if(win_player_1(A) == 1)
		return 1;
	else if(win_player_2(A) == 1)
		return 2;
	else if(empty(A)==0 && win_player_1(A)==0 && win_player_2(A)==0)
		return 3;
	else
		return 0;
}

int chances(char A[3][3]){
	// returns number of 0 and 1 in total
	int c=0,i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(A[i][j]!='_')
				c++;
		}
	}
	return c;
}


int win_player_2(char A[3][3]){
	int i,j;
	// Row wise
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			if(A[i][j]=='0' && A[i][j+1]=='0'){
				if(j==0){
					g_p=i;
					g_q=2;
				}
				else if(j==1){
					g_p=i;
					g_q=0;
				}
				if(A[g_p][g_q]=='_')
					return 1;
			}
		}
	}

	// Column wise
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			if(A[j][i]=='0' && A[j+1][i]=='0'){
				if(j==0){
					g_p=2;
					g_q=i;
				}
				else if(j==1){
					g_p=0;
					g_q=i;
				}
				if(A[g_p][g_q]=='_')
					return 1;
			}
		}
	}

	// Daigonal wise
	if(A[0][0]=='0' && A[1][1]=='0'){
		g_p=2;
		g_q=2;
		if(A[g_p][g_q]=='_')
			return 1;
	}
	if(A[1][1]=='0' && A[2][2]=='0'){
		g_p=0;
		g_q=0;
		if(A[g_p][g_q]=='_')
			return 1;
	}
	if(A[0][2]=='0' && A[1][1]=='0'){
		g_p=2;
		g_q=0;
		if(A[g_p][g_q]==1)
			return 1;
	}
	if(A[2][0]=='0' && A[1][1]=='0'){
		g_p=0;
		g_q=2;
		if(A[g_p][g_q]=='_')
			return 1;
	}

	// partial row
	for(i=0;i<3;i++){
		if(A[i][0]=='0' && A[i][2]=='0'){
			g_p=i;
			g_q=1;
		if(A[g_p][g_q]=='_')
			return 1;
		}
	}

	// partial column
	for(i=0;i<3;i++){
		if(A[0][i]=='0' && A[2][i]=='0'){
			g_p=1;
			g_q=i;
		if(A[g_p][g_q]=='_')
			return 1;
		}
	}

	// partial diagonal
	if(A[0][0]=='0' && A[2][2]=='0'){
		g_p=1;
		g_q=1;
		if(A[g_p][g_q]=='_')
			return 1;
	}
	if(A[0][2]=='0' && A[2][0]=='0'){
		g_p=1;
		g_q=1;
		if(A[g_p][g_q]=='_')
			return 1;
	}

	return 0;
}


int win_player_1(char A[3][3]){

	int i,j;
	// Row wise
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			if(A[i][j]=='1' && A[i][j+1]=='1'){
				if(j==0){
					g_p=i;
					g_q=2;
				}
				else if(j==1){
					g_p=i;
					g_q=0;
				}
			if(A[g_p][g_q]=='_')
				return 1;
			}
		}
	}

	// Column wise
	for(i=0;i<3;i++){
		for(j=0;j<2;j++){
			if(A[j][i]=='1' && A[j+1][i]=='1'){
				if(j==0){
					g_p=2;
					g_q=i;
				}
				else if(j==1){
					g_p=0;
					g_q=i;
				}
				if(A[g_p][g_q]=='_')
					return 1;
			}
		}
	}

	// Daigonal wise
	if(A[0][0]=='1' && A[1][1]=='1'){
		g_p=2;
		g_q=2;
		if(A[g_p][g_q]=='_')
			return 1;
	}
	if(A[1][1]=='1' && A[2][2]=='1'){
		g_p=0;
		g_q=0;
		if(A[g_p][g_q]=='_')
			return 1;
	}
	if(A[0][2]=='1' && A[1][1]=='1'){
		g_p=2;
		g_q=0;
		if(A[g_p][g_q]=='_')
			return 1;
	}
	if(A[2][0]=='1' && A[1][1]=='1'){
		g_p=0;
		g_q=2;
		if(A[g_p][g_q]=='_')
			return 1;
	}

	// partial row
	for(i=0;i<3;i++){
		if(A[i][0]=='1' && A[i][2]=='1'){
			g_p=i;
			g_q=1;
			if(A[g_p][g_q]=='_')
				return 1;
		}
	}

	// partial column
	for(i=0;i<3;i++){
		if(A[0][i]=='1' && A[2][i]=='1'){
			g_p=1;
			g_q=i;
			if(A[g_p][g_q]=='_')
				return 1;
		}
	}

	// partial diagonal
	if(A[0][0]=='1' && A[2][2]=='1'){
		g_p=1;
		g_q=1;
		if(A[g_p][g_q]=='_')
			return 1;
	}
	if(A[0][2]=='1' && A[2][0]=='1'){
		g_p=1;
		g_q=1;
		if(A[g_p][g_q]=='_')
			return 1;
	}

	return 0;
}




// empty 1 means empty space available
// empty 0 means no empty place available
int empty(char A[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(A[i][j]=='_')
				return 1;
		}
	}
	return 0;
}

int win(char A[3][3]){
	int i,j,c,d;
	// c for p1
	// d for p2
	// checking row wise
	for(i=0;i<3;i++){
		c=0;d=0;
		for(j=0;j<3;j++){
			if(A[i][j]=='0')
				c=c+1;
			else if(A[i][j]=='1')
				d=d+1;
		}
		if(c==3)
			return 1;
		else if(d==3)
			return 2;
	}

	// checking columnwise
	for(i=0;i<3;i++){
		c=0;d=0;
		for(j=0;j<3;j++){
			if(A[j][i]=='0')
				c=c+1;
			else if(A[j][i]=='1')
				d=d+1;
		}
		if(c==3)
			return 1;
		else if(d==3)
			return 2;
	}

	// checking daigonal wise
	c=0;
	d=0;
	for(i=0;i<3;i++){
		if(A[i][i]=='0')
			c=c+1;
		else if(A[i][i]=='1')
			d=d+1;
	}
	if(c==3)
		return 1;
	else if(d==3)
		return 2;
	return 0;
}

void append(int A[6][2],int a,int b){
	int i=0;
	while(A[i][0]!=-1){
	i++;
	}
	A[i][0]=a;
	A[i][1]=b;
	A[i+1][0]=-1;
	A[i+1][1]=-1;
}
