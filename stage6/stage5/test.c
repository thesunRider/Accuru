#include "stdio.h"

#define CD 5863276
#define MKDIR 210720772860
#define PWD 193502992


static const long int hash(const char *str) {
    unsigned long hash = 5381;  
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}


int main(int argc, char *arg[]) {


	char *p_cmd = arg[1];
	char *p_op = arg[2];
    printf("#define %s %d",p_op,hash(p_cmd));

    switch (hash(p_cmd)){
    	case HI:
    	printf("hi");
    	break;

    	case BRO:
    	printf("bro");
    	break;
    }
}