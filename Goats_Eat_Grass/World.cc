#include<iostream>
#include<string.h>
#include <stdlib.h>
#include "Creature.h"
#include "Goat.h"
#include "Grass.h"
#include "World.h"
using namespace std;
World::World(int numPasses,int seed){
	for(int ii=0;ii<20;ii++){
		for(int jj=0;jj<35;jj++){
			map[ii][jj]=NULL;
		}
	}
	pass=numPasses;
	srand(seed);
	for(int i=0;i<5;i++){
		int p=rand()%20, q=rand()%35;
		if(map[p][q]==NULL){
			Goat *goat=new Goat(0,20,1);
			map[p][q]=goat;
		}
		else
			i--;
	}
	for(int j=0;j<10;j++){
		int p=rand()%20, q=rand()%35;
		if(map[p][q]==NULL){
			Grass *grass=new Grass(0,1);
			map[p][q]=grass;
		}
		else
			j--;
	}
}

void World::mainLoop(int displayInterval){
	int dir;
	for(int i=0;i<pass;i++){
		if(i==0){ //day 0 initial world
			cout<<' '<<"0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4"<<endl;
			for(int a=0;a<20;a++){
				if(a<=9){
					cout<<a;
				}
				else if(a>9){
					cout<< a%10 ;
				}
				for(int b=0;b<70;b++){
					if(b%2==0 && map[a][b/2]!=NULL && map[a][b/2]->getid()==1){
						cout<<'X';
					}
					else if(b%2==0 && map[a][b/2]!=NULL && map[a][b/2]->getid()==2){
						cout<<'I';
					}
					else {
						cout<<' ';
					}
				}
				cout<<endl;
			}
			cout<<"------------------------------------------------------------------------"<<endl;
		}

		else{
			for(int a=0;a<20;a++){
				for(int b=0;b<35;b++){
					if(map[a][b]!=NULL){
						if(map[a][b]->getid()==2 && map[a][b]->getaction()==i){
								map[a][b]->updateage();
						}
						if(map[a][b]->getid()==1 && map[a][b]->getaction()==i){
								map[a][b]->updateage();	
								map[a][b]->updatepoint(-1);
						}
						dir=map[a][b]->getdirect();
						if(map[a][b]->getid()==1 && (map[a][b]->getage()>=50 && map[a][b]->getage()<=55)){
							if(a-1>=0 && dir==0){
								if(map[a-1][b]==NULL){
									Goat *goat=new Goat(0,20,i+1);
									map[a-1][b]=goat; //born goat
									map[a][b]->updateaction();
								}
								else if(map[a-1][b]!=NULL && map[a-1][b]->getid()==2){
									map[a-1][b]=NULL;
									Goat *goat=new Goat(0,20,i+1);
									map[a-1][b]=goat; //born goat
									map[a][b]->updateaction();
									map[a][b]->updatepoint(5);
								}
								else if(a-1<0 || (map[a-1][b]!=NULL && map[a-1][b]->getid()==1)){
									dir=map[a][b]->getdirect();
								}
							}
							else if(a+1<20 && dir==1){
								if(map[a+1][b]==NULL ){
									Goat *goat=new Goat(0,20,i+1);
									map[a+1][b]=goat; //born goat
									map[a][b]->updateaction();
								}
								else if(map[a+1][b]!=NULL && map[a+1][b]->getid()==2){
									map[a+1][b]=NULL;
									Goat *goat=new Goat(0,20,i+1);
									map[a+1][b]=goat; //born goat
									map[a][b]->updateaction();
									map[a][b]->updatepoint(5);
								}
								else if(a+1>=20 || (map[a+1][b]!=NULL && map[a+1][b]->getid()==1)){
									dir=map[a][b]->getdirect();
								}
							}
							else if(b-1>=0 && dir==2){
								if(map[a][b-1]==NULL ){
									Goat *goat=new Goat(0,20,i+1);
									map[a][b-1]=goat; //born goat
									map[a][b]->updateaction();	
								}
								else if(map[a][b-1]!=NULL && map[a][b-1]->getid()==2){
									map[a][b-1]=NULL;
									Goat *goat=new Goat(0,20,i+1);
									map[a][b-1]=goat; //born goat
									map[a][b]->updateaction();
									map[a][b]->updatepoint(5);
								}
								else if(b-1<0 || (map[a][b-1]!=NULL && map[a][b-1]->getid()==1)){
									dir=map[a][b]->getdirect();
								}
							}
							else if(b+1<35 && dir==3){
								if(map[a][b+1]==NULL ){
									Goat *goat=new Goat(0,20,i+1);
									map[a][b+1]=goat; //born goat
									map[a][b]->updateaction();
								}
								else if(map[a][b+1]!=NULL && map[a][b+1]->getid()==2){
									map[a][b+1]=NULL;
									Goat *goat=new Goat(0,20,i+1);
									map[a][b+1]=goat; //born goat
									map[a][b]->updateaction();
									map[a][b]->updatepoint(5);			
								}
								else if(b+1>35 || (map[a][b+1]!=NULL && map[a][b+1]->getid()==1)){
									dir=map[a][b]->getdirect();
								}
							}
						}
						if(map[a][b]->getid()==2 && (map[a][b]->getage()>=3 && map[a][b]->getage()<=5)){
							if(a-1>=0 && map[a-1][b]==NULL && dir==0){
								Grass *grass=new Grass(0,i+1);
								map[a-1][b]=grass; 
							}
							else if(a+1<20 && map[a+1][b]==NULL && dir==1){
								Grass *grass=new Grass(0,i+1);
								map[a+1][b]=grass; 
							}
							else if(b-1>=0 && map[a][b-1]==NULL && dir==2){
								Grass *grass=new Grass(0,i+1);
								map[a][b-1]=grass; 
							}
							else if(b+1<35 && map[a][b+1]==NULL && dir==3){
								Grass *grass=new Grass(0,i+1);
								map[a][b+1]=grass; 
							}
							map[a][b]->updateaction();
						}
						if(map[a][b]->getid()==2 && map[a][b]->getage()<3 && map[a][b]->getaction()==i){
							map[a][b]->updateaction();	
						}
						if(map[a][b]!=NULL && map[a][b]->getid()==1 && (map[a][b]->getage()>=70 || map[a][b]->getpoint()<=0)){
							map[a][b]=NULL; //goat die
						}
						if(map[a][b]!=NULL && map[a][b]->getid()==2 && map[a][b]->getage()>=6){
							map[a][b]=NULL;	 //grass die	
						}
					}
					if(map[a][b]!=NULL && map[a][b]->getid()==1 && dir==0){  //up
						if(a-1>=0 && ((map[a-1][b]!=NULL && map[a-1][b]->getid()==2 ) || map[a-1][b]==NULL)){
							if(map[a][b]->getaction()==i){
								map[a][b]->updateaction();			
								if(map[a-1][b]!=NULL && map[a-1][b]->getid()==2){
									map[a][b]->updatepoint(5); //eat grass
								}
								map[a-1][b]=map[a][b];
								map[a][b]=NULL;		
							}	
						}
						else if((a-1<0 || map[a-1][b]->getid()==1) && map[a][b]->getaction()==i){
							map[a][b]->updateaction();			
						}
					}
					else if(map[a][b]!=NULL && map[a][b]->getid()==1 && dir==1){ //down
						if(a+1<20 && ((map[a+1][b]!=NULL && map[a+1][b]->getid()==2) || map[a+1][b]==NULL)){
							if(map[a][b]->getaction()==i){
								map[a][b]->updateaction();			
								if(map[a+1][b]!=NULL && map[a+1][b]->getid()==2){
									map[a][b]->updatepoint(5);
								}
								map[a+1][b]=map[a][b];
								map[a][b]=NULL;	
							}	
						}
						else if((a+1>=20 || map[a+1][b]->getid()==1) && map[a][b]->getaction()==i){
							map[a][b]->updateaction();			
						}
					}
					else if(map[a][b]!=NULL && map[a][b]->getid()==1 && dir==2){ //left
						if(b-1>=0 && ((map[a][b-1]!=NULL && map[a][b-1]->getid()==2) || map[a][b-1]==NULL)){
							if(map[a][b]->getaction()==i){
								map[a][b]->updateaction();			
								if(map[a][b-1]!=NULL && map[a][b-1]->getid()==2){
									map[a][b]->updatepoint(5);
								}
								map[a][b-1]=map[a][b];
								map[a][b]=NULL;
							}
						}
						else if((b-1<0 || map[a][b-1]->getid()==1) && map[a][b]->getaction()==i){
							map[a][b]->updateaction();			
						}
					}
					else if(map[a][b]!=NULL && map[a][b]->getid()==1 && dir==3){ //right
						if(b+1<35 && ((map[a][b+1]!=NULL && map[a][b+1]->getid()==2) || map[a][b+1]==NULL)){
							if(map[a][b]->getaction()==i){
								map[a][b]->updateaction();			
								if(map[a][b+1]!=NULL && map[a][b+1]->getid()==2){
									map[a][b]->updatepoint(5);
								}
								map[a][b+1]=map[a][b];
								map[a][b]=NULL;
							}		
						}
						else if((b+1>=35 || map[a][b+1]->getid()==1) && map[a][b]->getaction()==i){
							map[a][b]->updateaction();			
						}		
					}				
				}
			}
			if(i%displayInterval==0){ //when i need to print
				//cout << "now : " << i << endl;
				cout<<' '<<"0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4"<<endl;
				for(int a=0;a<20;a++){
					if(a<=9){
						cout<<a;
					}
					else if(a>9){
						cout<< a%10 ;
					}
					for(int b=0;b<70;b++){
						if(b%2==0 && map[a][b/2]!=NULL && map[a][b/2]->getid()==1){
							cout<<'X';
						}
						else if(b%2==0 && map[a][b/2]!=NULL && map[a][b/2]->getid()==2){
							cout<<'I';
						}
						else {
							cout<<' ';
						}
					}
					cout<<endl;
				}
				cout<<"------------------------------------------------------------------------"<<endl;
			}
		}
	}	
}
