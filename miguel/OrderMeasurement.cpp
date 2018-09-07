// OrderMeasurement.cpp: Shows the relative runtime for an algorithm of order n, n-squared, and n-cubed.
//                       The data is written to files and is plotted using plot.ly, found at:
//                       https://plot.ly/create/#/
//

#include <stdio.h>
#include <windows.h>

void doOrderOne();
void doOrderTwo();
void doOrderThree();

int main()
{
	int orderOfMagnitude;
	printf("Enter the order of magnitude (1-3): ");
	scanf("%d", &orderOfMagnitude);
	switch (orderOfMagnitude) {
	case 1:
		doOrderOne();
		break;
	case 2:
		doOrderTwo();
		break;
	case 3:
		doOrderThree();
		break;
	default:
		printf("Invalid input. Terminating...\n");
		return -1;
	}

    return 0;
}

void doOrderOne() {
	int n;
	double startTime, endTime, totalTime;
	FILE *fp = fopen("orderOne.txt", "w");
	for (n = 0; n <= 80; ++n) {
		startTime = GetTickCount();
		for (int i = 0; i < n; ++i) {
			Sleep(10);
		}
		endTime = GetTickCount();
		totalTime = (endTime - startTime)/1000.0;
		printf("%3d %lf\n", n, totalTime);
		fprintf(fp, "%lf,\n", totalTime);//CSV format for plot.ly
		fflush(fp);
	}
	fclose(fp);
}

void doOrderTwo() {
	int n;
	double startTime, endTime, totalTime;
	FILE *fp = fopen("orderTwo.txt", "w");
	for (n = 0; n <= 40; ++n) {
		startTime = GetTickCount();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				Sleep(1);
			}
		}
		endTime = GetTickCount();
		totalTime = (endTime - startTime) / 1000.0;
		printf("%3d %lf\n", n, totalTime);
		fprintf(fp, "%lf,\n", totalTime);//CSV format for plot.ly
		fflush(fp);
	}
	fclose(fp);
}


void doOrderThree() {
	int n;
	double startTime, endTime, totalTime;
	FILE *fp = fopen("orderThree.txt", "w");
	for (n = 0; n <= 20; ++n) {
		startTime = GetTickCount();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					Sleep(1);
				}
			}
		}
		endTime = GetTickCount();
		totalTime = (endTime - startTime) / 1000.0;
		printf("%3d %lf\n", n, totalTime);
		fprintf(fp, "%lf,\n", totalTime);//CSV format for plot.ly
		fflush(fp);
	}
	fclose(fp);
}

