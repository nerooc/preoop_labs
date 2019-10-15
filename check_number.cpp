#include "check_number.h"
#include <cstring>
#include <cstdio>
#include <stdlib.h>


char find_ctrl(const char *karta){

	int x = strlen(karta);
	char strsuma;
	int suma = 0;
	int suma1 = 0;
	int suma2 = 0;

	char *strtmp1;
	

	int ctrl;
	
		if(x==16){
			for(int i = x - 1; i >= 0 ; i--){

				if(!(i%2)){
				 
					 if((karta[i] - '0')*2 >= 10){
						int k = (karta[i] - '0')*2;
						sprintf(strtmp1, "%d", k); 
						suma1 += (strtmp1[0]-'0') + (strtmp1[1]-'0');

					 }

					 else{
					 	suma1 += (karta[i] - '0')*2;
					 }
			
				}  

				else{	
				 
					 	suma2 += (karta[i] - '0');
				

				}
			}

		}

		else{
			for(int i = (16-x-1); i >= 0 ; i--){

				if(!(i%2)){
				 
					 if((karta[i] - '0')*2 >= 10){
						int k = (karta[i] - '0')*2;
						sprintf(strtmp1, "%d", k); 
						suma1 += (strtmp1[0]-'0') + (strtmp1[1]-'0');

					 }

					 else{
					 	suma1 += (karta[i] - '0')*2;
					 }
			
				}  

				else{	
				 
					 	suma2 += (karta[i] - '0');
				

				}
			}
			
		}
		
	
	suma = suma1 + suma2;	

	ctrl = suma % 10;

	strsuma = ctrl + '0';
	
	if(ctrl == 0){
		return '0';
	}

	else{
		return strsuma;
	}
}

bool number_correct(const char *karta){
	
	if(find_ctrl(karta) == '0'){
		return true;
	}
	else{
		return false;
	}
	
}
