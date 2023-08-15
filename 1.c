#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Register {
    int value;
};

void Showcontent(struct Register *A, struct Register *B, struct Register *C, struct Register *D, struct Register *H, struct Register *L, struct Register *M) {
    printf("|A=%d|\t", A->value);
    printf("|B=%d|\n", B->value);
    printf("|C=%d|\t", C->value);
    printf("|D=%d|\n", D->value);
    printf("|L=%d|\t", L->value);
    printf("|H=%d|\n", H->value);

    printf("|M=%d|\n", M->value);
    return;
}

int main() {
    struct Register A, B, C, D, H, L, M, Status;
    A.value = B.value = C.value = D.value = H.value = L.value = 11111111;
    char *portion;
    char space = ' ', comma = ',';
    int value;
    char s[100], exit_cmd[] = "EXIT", show_cmd[] = "SHOW", instruction[100];

    printf("Make sure to enter the value in binary. Current memory at 4000. Enter NEW to start, Press EXIT to stop the program,\n and SHOW to show the contents of the registers.\n ");
    gets(s);

    if (strcmp(s, exit_cmd) == 0) {
        printf("Bye");
    } else {
        while (1) {
            printf("Enter instruction\n");
            gets(instruction);

            if (strcmp(instruction, exit_cmd) == 0) {
                break;
            }
            
            if (strcmp(instruction, show_cmd) == 0) {
                Showcontent(&A, &B, &C, &D, &H, &L, &M);
                continue;  // Skip the rest of the loop and go back to input
            }

            portion = strtok(instruction, &space);
            if (portion != NULL && strcmp(portion, "CMA") == 0) {
                A.value = 11111111 - A.value;
            }

            if (strcmp(portion, "MOV") == 0) {
                portion = strtok(NULL, &space);
                if (strcmp(portion, "A,B") == 0) {
                    A.value = B.value;
                }
                // Add more cases for other MOV instructions
                if (strcmp(portion, "B,A") == 0) {
                    B.value = A.value;
                }if (strcmp(portion, "C,B") == 0) {
                    C.value = B.value;
                }if (strcmp(portion, "B,C") == 0) {
                    B.value = C.value;
                }if (strcmp(portion, "C,D") == 0) {
                    C.value = D.value;
                }if (strcmp(portion, "D,C") == 0) {
                    D.value = C.value;
                }
            }

            if (strcmp(portion, "MVI") == 0) {
                portion = strtok(NULL, &comma);
                if (strcmp(portion, "A") == 0) {
                    portion = strtok(NULL, &space);
                    value = atoi(portion);
                    A.value = value;
                }
                if (strcmp(portion, "B") == 0) {
                    portion = strtok(NULL, &space);
                    value = atoi(portion);
                    B.value = value;
                }
                 if (strcmp(portion, "C") == 0) {
                    portion = strtok(NULL, &space);
                    value = atoi(portion);
                    C.value = value;
                }
                 if (strcmp(portion, "D") == 0) {
                    portion = strtok(NULL, &space);
                    value = atoi(portion);
                    D.value = value;
                }
            }
        }
    }

    return 0;
}
