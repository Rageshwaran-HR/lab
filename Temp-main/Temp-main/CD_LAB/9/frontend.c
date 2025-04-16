#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int pos;
    char op[5], arg1[10], arg2[10], res[10];
} TAC;

TAC tac[MAX];
int tCount = 0, lCount = 0, tacIndex = 0;

void newTemp(char *t) { sprintf(t, "t%d", tCount++); }
void newLabel(char *l) { sprintf(l, "L%d", lCount++); }

void addTAC(char *op, char *a1, char *a2, char *res) {
    tac[tacIndex] = (TAC){tacIndex + 1, "", "", "", ""};
    strcpy(tac[tacIndex].op, op);
    strcpy(tac[tacIndex].arg1, a1);
    strcpy(tac[tacIndex].arg2, a2);
    strcpy(tac[tacIndex].res, res);
    tacIndex++;
}

void parseAssign(char *line) {
    char l[10], a1[10], a2[10], op[3], tmp[10];
    if (sscanf(line, "%[^=]=%[^+*/-]%[+*/-]%s", l, a1, op, a2) == 4) {
        // a = b + c
        newTemp(tmp);
        addTAC(op, a1, a2, tmp);
        addTAC(":=", tmp, "", l);
    } else if (sscanf(line, "%[^=]=%s", l, a1) == 2) {
        // a = 5
        addTAC(":=", a1, "", l);
    }
}

void parseIf(char *line) {
    char a1[10], a2[10], op[3], tmp[10], lbl[10];
    const char *start = strchr(line, '(');
    const char *end = strchr(line, ')');
    if (!start || !end) return;

    char cond[30];
    strncpy(cond, start + 1, end - start - 1);
    cond[end - start - 1] = '\0';

    sscanf(cond, "%[^<>=!]%2[<>=!]%s", a1, op, a2);
    newTemp(tmp);
    newLabel(lbl);
    addTAC(op, a1, a2, tmp);
    addTAC("if", tmp, "goto", lbl);
}

void printTAC() {
    printf("\n%-4s %-4s %-8s %-8s %-8s\n", "Pos", "Op", "Arg1", "Arg2", "Res");
    for (int i = 0; i < tacIndex; i++)
        printf("%-4d %-4s %-8s %-8s %-8s\n", tac[i].pos, tac[i].op, tac[i].arg1, tac[i].arg2, tac[i].res);
}

int main() {
    char line[50];
    FILE *f = fopen("input.txt", "r");
    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = 0; // remove newline
        if (strstr(line, "if")) parseIf(line);
        else if (strchr(line, '=')) parseAssign(line);
    }
    fclose(f);
    printTAC();
    return 0;
}
