//597MB Verilogs to Dimacs file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reset(char *la, int num_elements) {
	int i;
	for(i = 0; i < num_elements; i++) {
		la[i] = '\0';
	}
}



int main() {

	int n_reg=0; 
	int num;
	int n_transition = 0;
	int i;
	int fcount;
	int number_of_variables = 1;
	int number_of_clauses = 0;
	int reg_location[50] = {0};
	int newreg_location[50] = {0};
	int state[50] = {-1};
	
	FILE *fptr;
	FILE *fnew;

	char a[3000];
	
	char writebuffer[100];
	reset(writebuffer,100);

	char filename[20];
	char writefilename[25];
	
	printf("Insert Verilog Filename (w/o ext.): ");
	scanf("%s", filename);
	printf("\n");
	
	printf("Insert Number of Transitons: ");
	scanf("%d", &n_transition);
	printf("\n");

	//strcpy(filename,"ex1");
//	n_transition = 1;

	strcpy(writefilename,filename);
	strcat(writefilename,".dimacs");
	
	strcat(filename,".v");
	fptr = fopen(filename, "r");
	
	if(fptr == NULL) {
		printf("\nREAD ERROR\n");
		return(-1);
	}

	fnew = fopen(writefilename, "w");
	
	    if (fnew == NULL) {
        printf("Write Error!");
        exit(1);
    	}
	fprintf(fnew, "%s", "c DIMACS CONVERSION: ");
	fprintf(fnew, "%s", filename);





	char variables[800][20];

	for (i = 0; i<800; i++) {
		variables[i][0]	= '\0';
	}


	reset(a,3000);
	while( fgets(a, 3000, fptr) != NULL ) {


		//input
		if (a[0] == 'i' && a[1] == 'n' && a[2]== 'p' && a[3]== 'u' && a[4]== 't') {
			int i;
			for (i = 0; i <3000; i++) {
				if (a[i] == ' ') {
					num = i+1;
				}

				else if (a[i] == ',') {
					int counter=0;
					while(num<i) {
						variables[number_of_variables][counter] = a[num];
						counter++;
						variables[number_of_variables][counter] = '\0';
						num++;
					}
					num = i+1;

					number_of_variables ++;
				}

				else if (a[i] == ';') {
					int counter=0;
					while(num<i) {
						variables[number_of_variables][counter] = a[num];
						counter++;
						variables[number_of_variables][counter] = '\0';
						num++;
					}

					num = i+1;
					number_of_variables ++;
				}
			}
		}

		//output
		else if (a[0] == 'o' && a[1] == 'u' && a[2]== 't' && a[3]== 'p' && a[4]== 'u' && a[5]== 't') {
			int i;
			for (i = 0; i <3000; i++) {
				if (a[i] == ' ') {
					num = i+1;
				}

				else if (a[i] == ',') {
					int counter=0;
					while(num<i) {
						variables[number_of_variables][counter] = a[num];
						counter++;
						variables[number_of_variables][counter] = '\0';
						num++;
					}
					num = i+1;

					number_of_variables ++;
				}

				else if (a[i] == ';') {
					int counter=0;
					while(num<i) {
						variables[number_of_variables][counter] = a[num];
						counter++;
						variables[number_of_variables][counter] = '\0';
						num++;
					}

					num = i+1;
					number_of_variables ++;
				}
			}
		}

		//wire
		else if (a[0] == 'w' && a[1] == 'i' && a[2]== 'r' && a[3]== 'e') {
			int i;
			for (i = 0; i <3000; i++) {
				if (a[i] == ' ') {
					num = i+1;
				}

				else if (a[i] == ',') {
					int counter=0;
					while(num<i) {
						variables[number_of_variables][counter] = a[num];
						counter++;
						variables[number_of_variables][counter] = '\0';
						num++;
					}


					num = i+1;
					number_of_variables ++;
				}

				else if (a[i] == ';') {
					int counter=0;
					while(num<i) {
						variables[number_of_variables][counter] = a[num];
						counter++;
						variables[number_of_variables][counter] = '\0';
						num++;
					}

					num = i+1;
					number_of_variables ++;
				}
			}
		}

		//reg
		else if (a[0] == 'r' && a[1] == 'e' && a[2]== 'g') {
			int i;
			for (i = 0; i <3000; i++) {
				if (a[i] == ' ') {
					num = i+1;
				}

				else if (a[i] == ',') {
					int counter=0;
					while(num<i) {
						variables[number_of_variables][counter] = a[num];
						counter++;
						variables[number_of_variables][counter] = '\0';
						num++;
					}
					num = i+1;
					
					reg_location[n_reg] = number_of_variables;
					number_of_variables ++;
					n_reg++;
				}

				else if (a[i] == ';') {
					int counter=0;
					while(num<i) {
						variables[number_of_variables][counter] = a[num];
						counter++;
						variables[number_of_variables][counter] = '\0';
						num++;
					}

					num = i+1;
					
					reg_location[n_reg] = number_of_variables;
					number_of_variables ++;
					n_reg++;
				}
			}
		}
		//AND
		else if (a[0] == 'a' && a[1] == 'n' && a[2]== 'd') {
			number_of_clauses = number_of_clauses + (3*n_transition);
		}
		//NOT
		else if (a[0] == 'n' && a[1] == 'o' && a[2]== 't') {
			number_of_clauses = number_of_clauses + (2*n_transition);
		}
	reset(a,3000);
	}
	
	int n_var;
	n_var = (number_of_variables-1) * n_transition;
	int nclause = 0;
	
	nclause = ((n_transition-1)*n_reg)*2;
	
	nclause = number_of_clauses + nclause+n_reg;

	
	
	printf("\nNumber of Variables: %d\n",n_var);
	printf("Number of Clauses: %d\n\n",nclause);
	
	fprintf(fnew, "%s", "\nc");
	fprintf(fnew, "%s", "\nc Number of Variable = ");
	sprintf(writebuffer, "%i", n_var);
	fprintf(fnew, "%s", writebuffer);
	reset(writebuffer,100);
	fprintf(fnew, "%s", "\nc Number of Clauses = ");
	sprintf(writebuffer, "%i", nclause);
	fprintf(fnew, "%s", writebuffer);
	reset(writebuffer,100);
	
	//PRINT VARIABLE LIST
	fprintf(fnew, "%s", "\nc PRINT VARIABLE LIST");
	for(i=1; i<number_of_variables ; i++) {
		
			fprintf(fnew, "%s", "\nc   ");
			int ncount = 0;
			while(ncount < n_transition)
			{
				int multiples;
				multiples = ((number_of_variables-1)*ncount)+i;
				
				printf("%i",multiples);
				
				reset(writebuffer,100);
				sprintf(writebuffer, "%i", multiples);
				fprintf(fnew, "%s", writebuffer);
			//	fprintf(fnew, "%s", " ");
				
				if(multiples < 10){
				fprintf(fnew, "%s", "     ");
				printf("     ");	
				}
				else if(multiples < 100){
				fprintf(fnew, "%s", "    ");	
				printf("    ");	
				}
				else if(multiples < 1000){
				fprintf(fnew, "%s", "   ");	
				printf("   ");	
				}
				
				fprintf(fnew, "%s", "; ");
				ncount++;	
			}
			
			
			fprintf(fnew, "%s", variables[i]);
			
			printf("%s\n",variables[i]);
	}
	

		
	fprintf(fnew, "%s", "\nc\np cnf ");
	sprintf(writebuffer, "%i", n_var);
	fprintf(fnew, "%s", writebuffer);
	reset(writebuffer,100);
	fprintf(fnew, "%s", " ");

	sprintf(writebuffer, "%i", nclause);
	
	fprintf(fnew, "%s", writebuffer);
	reset(writebuffer,100);
	fprintf(fnew, "%s", "\nc");
	
	
	fclose(fptr);
	
	
	fptr = fopen(filename, "r");
	reset(a,3000);

	
	while( fgets(a, 3000, fptr) != NULL ) {
		//AND
		if (a[0] == 'a' && a[1] == 'n' && a[2]== 'd') {

			int out, in0,in1;
			//current Variable declaration to map variable name to number
			char currentVariable[20];
			currentVariable[0] = '\0';

			int i;
			for (i = 0; i <3000; i++) {

				if (a[i] == '(') {
					num = i+1;
					out = number_of_variables+1;
				}

				else if (a[i] == ',') {
					currentVariable[0] = '\0';
					int counter=0;
	
					while(num<i) {
						currentVariable[counter] = a[num];
						counter++;
						currentVariable[counter] = '\0';
						num++;
					}
					num = i+1;
				
					char nums;
					int ii;
					for(ii=0; ii<number_of_variables ; ii++)	{
						nums = 0;
						
						while(nums<21){
							if (currentVariable[nums] == variables[ii][nums]) {
								nums++;
								if (currentVariable[nums] == '\0' && variables[ii][nums] == '\0'){
									nums = 25;
									if (out == number_of_variables+1){
										out = ii;
									}
									in0 = ii;
									ii = number_of_variables+1; 
								}
							}

							else {
								nums = 25;
							}		
						}	
					}		
				}
				

				else if (a[i] == ')') {
					currentVariable[0] = '\0';
					int counter=0;
					while(num<i) {
						currentVariable[counter] = a[num];
						counter++;
						currentVariable[counter] = '\0';
						num++;
					}
					num = i+1;
					
					char nums;
					int ii;
					for(ii=0; ii<number_of_variables ; ii++){
						nums = 0;
						while(nums<21){
							if (currentVariable[nums] == variables[ii][nums]) {
								nums++;
								if (currentVariable[nums] == '\0' && variables[ii][nums] == '\0'){
									nums = 23;
									in1 = ii;
									ii = number_of_variables+1; 
								}
							}

							else {
								nums = 21;
							}		
						}	
					}
				}
			}
			
			int ncount = 0;
			while(ncount < n_transition)
			{
				
		
				
			
			fprintf(fnew, "%s", "\nc ");
			fprintf(fnew, "%s", a);
			

			
			reset(writebuffer,100);
			sprintf(writebuffer, "%i",in0);
			fprintf(fnew, "%s", writebuffer);
			fprintf(fnew, "%s", " -");
			reset(writebuffer,100);
			sprintf(writebuffer, "%i", out);
			fprintf(fnew, "%s", writebuffer);
			reset(writebuffer,100);
			fprintf(fnew, "%s", " 0\n");
			
			sprintf(writebuffer, "%i", in1);
			fprintf(fnew, "%s", writebuffer);
			fprintf(fnew, "%s", " -");
			reset(writebuffer,100);
			sprintf(writebuffer, "%i", out);
			fprintf(fnew, "%s", writebuffer);
			reset(writebuffer,100);
			fprintf(fnew, "%s", " 0\n-");
			
			sprintf(writebuffer, "%i", in0);
			fprintf(fnew, "%s", writebuffer);
			fprintf(fnew, "%s", " -");
			reset(writebuffer,100);
			sprintf(writebuffer, "%i", in1);
			fprintf(fnew, "%s", writebuffer);
			fprintf(fnew, "%s", " ");
			reset(writebuffer,100);
			sprintf(writebuffer, "%i", out);
			fprintf(fnew, "%s", writebuffer);
			reset(writebuffer,100);
			
			fprintf(fnew, "%s", " 0\nc");
			
			ncount++;
			
			in0 = ((number_of_variables-1) ) + in0;
			in1 = ((number_of_variables-1) ) + in1;
			out = ((number_of_variables-1) ) + out;
			
			
		}
		} //ELSEIF AND
		
		//not
		else if (a[0] == 'n' && a[1] == 'o' && a[2]== 't') {
			int out, in;
			//current Variable declaration to map variable name to number
			char currentVariable[20];
			currentVariable[0] = '\0';

			int i;
			for (i = 0; i <3000; i++) {

				if (a[i] == '(') {
					num = i+1;
				}

				else if (a[i] == ',') {
					currentVariable[0] = '\0';
					int counter=0;
					while(num<i) {
						currentVariable[counter] = a[num];
						counter++;
						currentVariable[counter] = '\0';
						num++;
					}
					num = i+1;
				
					char nums;
					int ii;
					for(ii=0; ii<number_of_variables ; ii++)	{
						nums = 0;
						
						while(nums<20){
							if (currentVariable[nums] == variables[ii][nums]) {
								nums++;
								if (currentVariable[nums] == '\0' && variables[ii][nums] == '\0'){
									nums = 21;
									out = ii;
									ii = number_of_variables+1; 
								}
							}

							else {
								nums = 21;
							}		
						}	
					}
		
				}
				

				else if (a[i] == ')') {
					currentVariable[0] = '\0';
					int counter=0;
					while(num<i) { //copy a to current variable nwme
						currentVariable[counter] = a[num];
						counter++;
						currentVariable[counter] = '\0';
						num++;
					}
					num = i+1;
					
					//search
					char nums;
					int ii;
					for(ii=0; ii<number_of_variables ; ii++){
						nums = 0;
						while(nums<20){
							if (currentVariable[nums] == variables[ii][nums]) {
								nums++;
								if (currentVariable[nums] == '\0' && variables[ii][nums] == '\0'){
									nums = 21;
									in = ii;
									ii = number_of_variables+1; 
								}
							}

							else {
								nums = 21;
							}		
						}	
					}
			
				}
			}
			
			
			int ncount = 0;
			while(ncount < n_transition)
			{	
				
				
				
				fprintf(fnew, "%s", "\nc ");
				fprintf(fnew, "%s", a);
				fprintf(fnew, "%s", "-");
			
				reset(writebuffer,100);
				sprintf(writebuffer, "%i", in);
				fprintf(fnew, "%s", writebuffer);
				fprintf(fnew, "%s", " -");
				reset(writebuffer,100);
				sprintf(writebuffer, "%i", out);
				fprintf(fnew, "%s", writebuffer);
				reset(writebuffer,100);
				fprintf(fnew, "%s", " 0\n");
				
				sprintf(writebuffer, "%i", in);
				fprintf(fnew, "%s", writebuffer);
				fprintf(fnew, "%s", " ");
				reset(writebuffer,100);
				sprintf(writebuffer, "%i", out);
				fprintf(fnew, "%s", writebuffer);
				reset(writebuffer,100);
				fprintf(fnew, "%s", " 0\nc");
				ncount++;
				
				in = ((number_of_variables-1) ) + in;
				out = ((number_of_variables-1)) + out;
				
			}
			
			
		} //ELSEIF NOT
		
		else if 
		(a[0] == '/' && a[1] == '/' && a[2]== 'S'&& a[3] == 't' && a[4] == 'a' && a[5]== 't'&& a[6] == 'e' && a[7] == ':' ) {	
		//count 0
		i=8;
		fcount = 0;
		
		while( i<3000){
			if(a[i] == '\0' || a[i]==10){
				i = 3001;
			}
			else{
				fcount++;
				i++;
			}
		}
		
		printf("Number of States Final Condition : %d\n",fcount); 
		
		int f;
		f = fcount;
		i=8;
		while( i < 8+fcount ){
			
			if(a[i] == '0'){
				state[f-1] = 0;
			}
			else if(a[i] == '1'){
				state[f-1] = 1;
			}
			else if(a[i] == 10){
			
			}
			else{
				printf("FINAL STATE ERROR");
				return(-1);
			}
			
			f--;
			i++;
		}	
		i=0;
		while( i < fcount ){
			printf("S%d : %d ",i,state[i]);
			i++;
		}
		
		}
		reset(a,3000);
}
	

	int s;
	

	for (i=0; i < n_reg; i++){  //GO TRHOU EACH REGISTER FLOP
		
		reset(writebuffer,100);
		writebuffer[0]='N'; 
			
		for (s=0; s<20; s++){ //NS REGISTERS
			
			writebuffer[s+1] =  variables[reg_location[i]][s];
			writebuffer[s+2] = '\0';
		}
	
		//search
		char nums;
		int ii;
		for(ii=0; ii<number_of_variables ; ii++){
			nums = 0;
			while(nums<20){
				
				if (writebuffer[nums] == variables[ii][nums]) {
					nums++;
					
					if (writebuffer[nums] == '\0' && variables[ii][nums] == '\0'){
						newreg_location[i] = ii;
						nums = 21;
					}
				}

				else {
					nums = 21;
				}		
			}	
		}
	}
	
	
	int in;
	int out;
	
	for (i=0; i < n_reg; i++){  //GO TRHOU EACH REGISTER FLOP
		int ncount = 0;
		in = newreg_location[i] + (number_of_variables-1);
		
		out = reg_location[i];
		
		while(ncount < n_transition-1)
		{
		  printf("IN: %d OUT: %d \n",in,out);
		  
		  	
			fprintf(fnew, "%s", "\nc Transition Buffer\n");
			fprintf(fnew, "%s", "-");
		
			reset(writebuffer,100);
			sprintf(writebuffer, "%i", out);
			fprintf(fnew, "%s", writebuffer);
			fprintf(fnew, "%s", " ");
			reset(writebuffer,100);
			sprintf(writebuffer, "%i", in);
			fprintf(fnew, "%s", writebuffer);
			reset(writebuffer,100);
			fprintf(fnew, "%s", " 0\n");
			
			sprintf(writebuffer, "%i", out);
			fprintf(fnew, "%s", writebuffer);
			fprintf(fnew, "%s", " -");
			reset(writebuffer,100);
			sprintf(writebuffer, "%i", in);
			fprintf(fnew, "%s", writebuffer);
			reset(writebuffer,100);
			fprintf(fnew, "%s", " 0\nc");
			
		  	in = in + (number_of_variables-1);
			out = out + (number_of_variables-1);
			ncount++;
		}
	
	}
	
	
fprintf(fnew, "%s", "\nc FINAL Condition ");	
	

	for (i=0; i <fcount; i++){  //GO TRHOU EACH REGISTER FLOP
		
		reset(writebuffer,100);
		writebuffer[0]='N'; 
		writebuffer[1]='S';	
		if (i<10){
			writebuffer[2] = i+'0';	
			writebuffer[3] = '\0';
		}
		else if(i<100){
			int a;
			a = i/10;
			writebuffer[2] = a +'0';
			a = a*10;
			a = i - a;
			writebuffer[3] = a+'0';
			writebuffer[4] = '\0';	
		}
	
			
	
		printf("\n\ni= %d NSx?: %s\n",i,writebuffer);
		
		//search
		char nums;
		int ii;
		for(ii=0; ii<number_of_variables ; ii++){
			nums = 0;
			while(nums<20){
				
				if (writebuffer[nums] == variables[ii][nums]) {
					nums++;
					
					if (writebuffer[nums] == '\0' && variables[ii][nums] == '\0'){
					//ii
						if (state[i]==0){
	
						fprintf(fnew, "%s", "\n");
						fprintf(fnew, "%s", "-");
						char abuffer[20];
						reset(abuffer,20);
						sprintf(abuffer, "%i", ii +((n_transition-1)*(number_of_variables-1)));
						fprintf(fnew, "%s", abuffer);
						fprintf(fnew, "%s", " 0");
						
						}
						else if (state[i]==1){
						fprintf(fnew, "%s", "\n");
						char abuffer[20];
						reset(abuffer,20);
						sprintf(abuffer, "%i", ii+((n_transition-1)*(number_of_variables-1)));
						fprintf(fnew, "%s", abuffer);
						fprintf(fnew, "%s", " 0");
						}
						
						else{
							printf("error in State");
						}
						
						
						
						
						
						nums = 21;
					}
				}

				else {
					nums = 21;
				}		
			}	
		}
	}
	
	
	
	fprintf(fnew, "%s", "\nc END OF DIMACS CNF");
	fclose(fptr);
	fclose(fnew);

	return 0;


}




