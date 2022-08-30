#include<stdio.h>

int main(int argc, char** argv){
	
	int v[] = {49,5,17,8,91,32,2,44,30};
	int i, j, tmp;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if(v[i] < v[j]){
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	for (i=0; i<9; i++){
		printf("\n%i", v[i]);
	}
	
	return 0;
}
