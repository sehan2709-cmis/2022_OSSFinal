#include "functions.h"

void startProject(){
    printf("   █▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n   █░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█\n   █░░║║║╠─║─║─║║║║║╠─░░█\n   █░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█\n   █▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n\n   2022-1 Open Source Laboratories Fianl Project\n   22100052 Sehan Kwon  |  English Word Synonym Dictionary for Essay\n\n");
    int end = 0;
    int project;
    
    while(end == 0){
        chooseFunction(&project);
        if(project == 0) symDic();
        else if(project == 1) transDic();
        else if(project == 2) advcDic();
        else if(project == 3) break;
    }

    printf("     \nThank You For Using :-)\n");
    return;
}

void chooseFunction(int* project){
    printf("\nChoose Which Mode You Will Use (Type an integer Number)\n     0) Word Search\n     1) Transition Words Dictionary\n     2) Advanced English Words Dictionary\n     3) Exit Project\n");
    
    while(1){
        printf("\n\n     Which Project: ");
        scanf("%d", project);
        if(*project >= 0 && *project <= 3)
            break;

        printf("     Please type an integer bumber between 0~3 to start.\n     4) for description\n");

        if(*project == 4)
            printf("\n\n Functions:\n     0) Word Search\n     1) Transition Words Dictionary\n     2) Advanced English Words Dictionary\n     3) Exit Project\n");
    }

    return;
}

void symDic(){
    FILE* adv = fopen("AEW.txt", "r");
    int index = -1, count, character = 0;
    char file[26][250][100] = {'\0'};
    char c[100];
    while(fgets(c, sizeof(c), adv) != NULL){
        if(c[0] == '(' && (c[1] >= 'A' && c[1] <= 'Z') && c[2] == ')'){
            index++;
            count = 0;
            continue;
        }

        for(int i = 0; i < 100; i++){
            if(i <= 4 && ((c[i] >= '0' && c[i] <= '9') || c[i] == '.')) continue;
            else{file[index][count][character] = c[i]; character++;}

            if(c[i] == '\0') break;
        }
        character = 0;
        count++;
    }

    int continuee = 1;
    char input[40] = {'\0'};

    int until, length = 0, found;
    count = 0;

    while(continuee == 1){
        printf("------------------------------------------\n     *****Advance Words Research*****\n\n     Input a word to search: ");
        scanf("%s", input);

        for(int i = 0; i < 40; i++){
            if(input[i] == '\0' || input[i] == '\n') break;
            length++;
        }

        if(length >= 1){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 250; j++){
                    if(file[i][j][0] == '\0') break;

                    for(int k = 0; k < 100-length; k++){

                        found = 1;

                        for(int l = 0; l < length; l++){
                            if(!(input[l] == file[i][j][k+l])){found = 0; break;}
                        }

                        if(found == 1){
                            count++;
                            if(count == 1){
                                printf("        Word Found!!!\n");
                            }
                            printf("           %d) %s\n", count, file[i][j]);
                            break;
                        }
                    }
                }
            }
        }

        if(count == 0){
            printf("        Nothing Found T^T\n");
        }

        while(1){
            printf("\n     continue? (yes: 1, exit: 0) ");
            scanf("%d", &continuee);
            printf("\n\n\n");

            if(continuee == 0 || continuee == 1) break;
        }

        count = 0;
        length = 0;
    }

    return;
}

void transDic(){
    FILE* trans = fopen("TSW.txt", "r");

    char tran[13][50] = {'\0'};
    char words[13][50][25] = {'\0'};
    char c[500] = {'\0'};

    int count = 0, word, character = 0;
    while(fgets(c, sizeof(c), trans) != NULL){
        if(count % 2 == 0){
            word = 0;
            character = 0;

            for(int i = 1; i < 50; i++){
                if(c[i] == '\0' || c[i] == ')') break;
                tran[count/2][i-1] = c[i];
            }
        } else{
            for(int i = 0; i < 500; i++){
                if(c[i] == '\0') break;
                else if(c[i] == ',' && c[i+1] == ' '){ i += 2; word++; character = 0;}

                words[count/2][word][character] = c[i];
                character++;
            }
        }
        count++;
    }

    int input, continuee;
    while(1){
        printf("------------------------------------------\n        Transitional Words\n");
        for(int i = 0; i < 13; i++){
            printf("        %d. %s\n", i, tran[i]);
        }
        printf("        13. exit\n");
        
        
        printf("\n     *input a number");
        printf("\n     Which transitional words would you like to see?: ");
        scanf("%d", &input);

        
        if(input == 13) break;
        else if(input >= 0 && input <= 25){
            printf("   Transitional Words (%s)\n", tran[input]);
            for(int i = 0; i < 50; i++){
                if(words[input][i][0] == '\0') break;
                printf("     %d. %s\n", i+1, words[input][i]);
            }

            printf("continue? (yes: 1, exit: 0) ");
            scanf("%d", &continuee);
            if(continuee == 0) break;
        } else{
            printf("\n     please input an integer number between 0~13\n");
        }
    }
    return;
}

void advcDic(){
    FILE* adv = fopen("AEW.txt", "r");
    int index = -1, count, character = 0;

    char file[26][250][100] = {'\0'};
    char c[100];

    while(fgets(c, sizeof(c), adv) != NULL){
        if(c[0] == '(' && (c[1] >= 'A' && c[1] <= 'Z') && c[2] == ')'){
            index++;
            count = 0;
            continue;
        }

        for(int i = 0; i < 100; i++){
            if(i <= 4 && ((c[i] >= '0' && c[i] <= '9') || c[i] == '.')) continue;
            else{file[index][count][character] = c[i]; character++;}

            if(c[i] == '\0') break;
        }
        character = 0;
        count++;
    }

    char alp[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int amout[26] = {0};

    for(int i = 0; i < 26; i++){
        if(file[i][0][0] == '\0') continue;
        else{
            for(int j = 0; j < 250; j++){
                if(file[i][j][0] == '\0') break;
                amout[i] = j+1;
            }
        }
    }

    int input, continuee;
    while(1){
        for(int i = 0; i < 26; i++){
            printf("        %d. Words Starts With (%c): %d words\n", i, alp[i], amout[i]);
        }
        printf("        26. exit\n");
        
        printf("\n     Which words would you like to see?: ");
        scanf("%d", &input);

        
        if(input == 26) break;
        else if(input >= 0 && input <= 25){
            printf("------------------------------------------\n   Advanced English Words That Starts With (%c)\n", alp[input]);
            for(int i = 0; i < 250; i++){
                if(file[input][i][0] == '\0') break;
                printf("     %s", file[input][i]);
            }
            printf("\n------------------------------------------\n");

            printf("continue? (yes: 1, exit: 0) ");
            scanf("%d", &continuee);
            if(continuee == 0) break;
        } else{
            printf("\n     please input an integer number between 0~26\n");
        }
    }

    fclose(adv);
    return;
}