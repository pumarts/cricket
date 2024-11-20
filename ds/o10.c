#include <stdio.h>
#include <string.h>
struct Record {
int flag;
int usn;
char name[20];
} rec[15];
int hash(int usn) {
return usn % 15;
}
void displayRecords() {
printf("\nThe Hash Table Content is:\n");
for (int i = 0; i < 15; i++) {
if (rec[i].flag == 1) {
printf("%s | %d\n", rec[i].name, rec[i].usn);
} else {
printf("## | ##\n");
}
}
}
int main() {
FILE *in, *outp;
int n, usn, loc;
for (int k = 0; k < 15; k++)
rec[k].flag = 0;
printf("Enter number of records to read from file (max %d): ", 15);
scanf("%d", &n);
if (n > 15) {
printf("Please provide less than or equal to %d records!\n", 15);
return 1;
}
in = fopen("input.txt", "r");
if (in == NULL) {
perror("Error opening input file");
return 1;
}
char name[20];
for (int i = 0; i < n; i++) {
fscanf(in, "%s %d", name, &usn);
loc = hash(usn);
while (rec[loc].flag == 1)
loc = (loc + 1) % 15;
strcpy(rec[loc].name, name);
rec[loc].usn = usn;
rec[loc].flag = 1;
}
fclose(in);
displayRecords();
outp = fopen("output.txt", "w");
if (outp == NULL) {
perror("Error opening output file");
return 1;
}
for (int i = 0; i < 15; i++) {
if (rec[i].flag == 1) {
fprintf(outp, "%s | %d\n", rec[i].name, rec[i].usn);
} else {
fprintf(outp, "## | ##\n");
}
}
fclose(outp);
return 0;
}