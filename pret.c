#include <stdio.h>
#include <math.h>

//calculates monthly payments
float monthlyPayments(float amount, float interest, float time) 
{
	//Calulate annual interest rate to monthly rate
	float monthlyRate = interest / 12;
	//Caluclate the numerator
	float numerator = amount * (monthlyRate / 100.0);
	//Calculate the denominator
    	float denominator = 1 - pow(1 + (monthlyRate / 100.0), -time * 12);
	//calculate monthly payment
    	float resMonthlyPayment = numerator / denominator;
    	return resMonthlyPayment;
}

float totalPayment(float time, float monthlyPayment)
{
	float res = (time * 12) * monthlyPayment;
	return res;
}

int main()
{
	//amount: money borrowed
	//interest: interest rate;
	//time: loan duration
	float amount, interest, time;
	int attempts = 0;
	int maxAttempts = 10;
	int minTime = 5;
	int minInterest = 3;
	int maxInterest = 7;
	char choice;

	printf("\n####################-Chaabi Lil Iskane Loan Simulation-####################\n\n\n");

	do{
		printf("Enter amount you want to borrow: ");
		scanf("%f", &amount);

		printf("Enter interest rate (between 3%% minimum and 7%% maximum): ");
		
		//check if interest rate is between 3% and 7%
		do{

			//check if attempts number reached
			if (attempts == maxAttempts)
				break;
	
			scanf("%f", &interest);

			if (interest < minInterest || interest > maxInterest)
				printf("Interest rate must be between 3%% and 7%%!\n");

			attempts++;

		}while(!(interest >= minInterest && interest <= maxInterest));

		if (attempts == maxAttempts)
			break;
			
		printf("Enter duration (minimum 5 years): ");

		//check if loan duration is atleast 5 years
		do{

			if (attempts == maxAttempts)
				break;

			scanf("%f", &time);

			if (time < minTime)
				printf("Loan Duration must be atleast 5 years!\n");
		
			attempts++;

		}while(!(time >= 5));

		if (attempts == maxAttempts)
			break;

		float res = monthlyPayments(amount, interest, time);
		float resTotalPayment = totalPayment(time, res);		

		//check if interest rate and loan duration are true to print the result
		if ((interest >= minInterest && interest <= maxInterest) && (time >= minTime))
		{
			printf("\n####################--Results--###################\n\n");

			printf("-- Money Borrowed : %.2f DH\n", amount);
			printf("-- Choosen interest rate: %.f%%\n", interest);
			printf("-- Loan duration: %.f years\n", time);
			printf("-- Estimated monthly payments: %.2f DH\n", res);
			printf("-- Total Payment: %.2f DH\n", resTotalPayment);

			printf("\n####################--Results--###################\n\n");
		}

		printf("Would you like to try another simulation? (Y/N): ");
		scanf(" %c", &choice);

		//check if User wants to try another simulation or quit the program
		if (choice == 'Y' || choice == 'y')
		{
			printf("\n------------------------------------\n");
			printf("\nAnother simulation is starting\n");
			printf("\n------------------------------------\n");
			continue;
		}		
		else
		{
			printf("\n--------------------------------------------------------------\n");
			printf("\nThank you for using our simulation, We hope to see you again!!\n");
			printf("\n--------------------------------------------------------------\n");
			break;
		}

	}while(attempts < maxAttempts);

	//check if attempts counter reached max number of attempts
	if (attempts >= maxAttempts)
		printf("You reached maximum attemepts, try again later!\n");

	printf("\n###########################################################################\n\n");
}
