void vertical(int h, int d) {

int max_dist = h - 2;
for (int i = 0; i < h; i++) {
if (i == 0 || i == h - 1) {
printf("N");
for (int j = 0; j < max_dist; j++) {
printf(" ");
}

printf("N");

for (int j = 0; j < d; j++) {
printf(" "); //for loop used, you may use while loop to create space from axis
}
printf("|");
for (int j = 0; j < d; j++) {
printf(" ");
}

printf("N");

for (int j = 0; j < max_dist; j++) {
printf(" "); //for loop used, you may use while loop to create space from axis
}

printf("N");

} 
  else {
printf("N");
for (int j = 1; j < i; j++) {
printf(" ");
}

printf("N");

for (int j = 0; j < h - i - 2; j++) {
printf(" ");
}

printf("N");

for (int j = 0; j < d; j++) {
printf(" "); //for loop used, you may use while loop to create space from axis
}

printf("|");

for (int j = 0; j < d; j++) {
printf(" "); //for loop used, you may use while loop to create space from axis
}

printf("N");

for (int j = 0; j < h - i - 2; j++) {
printf(" ");
}

printf("N");

for (int j = 1; j < i; j++) {
printf(" ");
}

printf("N");

}

printf("\n");

}

}

int main(int argc, char** argv)

{
// Size of the Pattern
int Size,space;
printf("Enter the size of the letter big N and enter the space from the axis ");
scanf("%d %d", &Size, &space);
// Calling the function to print the desired Pattern
vertical(Size, space);
}
