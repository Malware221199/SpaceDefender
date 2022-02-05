#include "Utility.h"

char *sprite_alieno[3]={{" ▓▓"}
                       ,{"▒▓ "}
                       ,{" ▓▓"}};

char *sprite_giocatore[6]={{"  ▓▓▓▓▓"}
                          ,{"   ▓▓  "}
                          ,{"▓▓▓▓▓▒"}
                          ,{"   ▓▓  "}
                          ,{"  ▓▓▓▓▓"}};

char *sprite_gioca[2]={{"█▀▀ █ █▀█ █▀▀ ▄▀█"}
                      ,{"█▄█ █ █▄█ █▄▄ █▀█"}};

char *sprite_opzioni[2]={{"█▀█ █▀█ ▀█ █ █▀█ █▄ █ █"}
                        ,{"█▄█ █▀▀ █▄ █ █▄█ █ ▀█ █"}};

char *sprite_esci[2]={{"█▀▀ █▀ █▀▀ █"}
                     ,{"██▄ ▄█ █▄▄ █"}};
                    
char *sprite_indietro[2]={{"█ █▄ █ █▀▄ █ █▀▀ ▀█▀ █▀█ █▀█"}
                         ,{"█ █ ▀█ █▄▀ █ ██▄  █  █▀▄ █▄█"}};

char *sprite_nemici[2]={{"█▄ █ █▀▀ █▀▄▀█ █ █▀▀ █"}
                       ,{"█ ▀█ ██▄ █ ▀ █ █ █▄▄ █"}};

char *sprite_difficolta[2]={{"█▀▄ █ █▀▀ █▀▀ █ █▀▀ █▀█ █   ▀█▀ ▄▀█"}
                           ,{"█▄▀ █ █▀  █▀  █ █▄▄ █▄█ █▄▄  █  █▀█"}};

char *sprite_num_nemici[2]={{"█▄ █ █ █ █▀▄▀█ █▀▀ █▀█ █▀█   █▄ █ █▀▀ █▀▄▀█ █ █▀▀ █ ▀"}
                           ,{"█ ▀█ █▄█ █ ▀ █ ██▄ █▀▄ █▄█   █ ▀█ ██▄ █ ▀ █ █ █▄▄ █ ▄"}};

char *sprite_difficile[2]={{"█▀▄ █ █▀▀ █▀▀ █ █▀▀ █ █   █▀▀"}
                          ,{"█▄▀ █ █▀  █▀  █ █▄▄ █ █▄▄ ██▄"}};

char *sprite_medio[2]={{"█▀▄▀█ █▀▀ █▀▄ █ █▀█"}
                      ,{"█ ▀ █ ██▄ █▄▀ █ █▄█"}};

char *sprite_facile[2]={{"█▀▀ ▄▀█ █▀▀ █ █   █▀▀"}
                       ,{"█▀  █▀█ █▄▄ █ █▄▄ ██▄"}};

char *sprite_space[7]={{"  ██████ ██▓███  ▄▄▄      ▄████▄ ▓█████"}
                      ,{"▒██    ▒▓██░  ██▒████▄   ▒██▀ ▀█ ▓█   ▀ "}
                      ,{"░ ▓██▄  ▓██░ ██▓▒██  ▀█▄ ▒▓█    ▄▒███   "}
                      ,{"  ▒   ██▒██▄█▓▒ ░██▄▄▄▄██▒▓▓▄ ▄██▒▓█  ▄ "}
                      ,{"▒██████▒▒██▒ ░  ░▓█   ▓██▒ ▓███▀ ░▒████▒"}
                      ,{"▒ ▒▓▒ ▒ ▒▓▒░ ░  ░▒▒   ▓▒█░ ░▒ ▒  ░░ ▒░ ░"}
                      ,{"░ ░▒  ░ ░▒ ░      ▒   ▒▒ ░ ░  ▒   ░ ░  ░"}};

char *sprite_defender[7]={{"▓█████▄▓█████  █████▓█████ ███▄    █▓█████▄▓█████ ██▀███  "}
                         ,{"▒██▀ ██▓█   ▀▓██   ▒▓█   ▀ ██ ▀█   █▒██▀ ██▓█   ▀▓██ ▒ ██▒"}
                         ,{"░██   █▒███  ▒████ ░▒███  ▓██  ▀█ ██░██   █▒███  ▓██ ░▄█ ▒"}
                         ,{"░▓█▄   ▒▓█  ▄░▓█▒  ░▒▓█  ▄▓██▒  ▐▌██░▓█▄   ▒▓█  ▄▒██▀▀█▄  "}
                         ,{"░▒████▓░▒████░▒█░   ░▒████▒██░   ▓██░▒████▓░▒████░██▓ ▒██▒"}
                         ,{" ▒▒▓  ▒░░ ▒░ ░▒ ░   ░░ ▒░ ░ ▒░   ▒ ▒ ▒▒▓  ▒░░ ▒░ ░ ▒▓ ░▒▓░"}
                         ,{" ░ ▒  ▒ ░ ░  ░░      ░ ░  ░ ░░   ░ ▒░░ ▒  ▒ ░ ░  ░ ░▒ ░ ▒░"}};

char *sprite_gameover[5]={{" ▄▄ •  ▄▄▄· • ▌ ▄ ·. ▄▄▄ .           ▌ ▐·▄▄▄ .▄▄▄ "}
                         ,{"▐█ ▀ ▪▐█ ▀█ ·██ ▐███▪▀▄.▀·    ▪     ▪█·█▌▀▄.▀·▀▄ █·"}
                         ,{"▄█ ▀█▄▄█▀▀█ ▐█ ▌▐▌▐█·▐▀▀▪▄     ▄█▀▄ ▐█▐█•▐▀▀▪▄▐▀▀▄ "}
                         ,{"▐█▄▪▐█▐█ ▪▐▌██ ██▌▐█▌▐█▄▄▌    ▐█▌.▐▌ ███ ▐█▄▄▌▐█•█▌"}
                         ,{"·▀▀▀▀  ▀  ▀ ▀▀  █▪▀▀▀ ▀▀▀      ▀█▄▀▪. ▀   ▀▀▀ .▀  ▀"}};

char *sprite_youwin[5]={{" ▄· ▄▌      ▄• ▄▌    ▄▄▌ ▐ ▄▌▪   ▐ ▄ "}
                       ,{"▐█▪██▌▪     █▪██▌    ██· █▌▐███ •█▌▐█"}
                       ,{"▐█▌▐█▪ ▄█▀▄ █▌▐█▌    ██▪▐█▐▐▌▐█·▐█▐▐▌"}
                       ,{" ▐█▀·.▐█▌.▐▌▐█▄█▌    ▐█▌██▐█▌▐█▌██▐█▌"}
                       ,{"  ▀ •  ▀█▄▀▪ ▀▀▀      ▀▀▀▀ ▀▪▀▀▀▀▀ █▪"}};

char *sprite_due[6]={{"██████╗ "}
                    ,{"╚════██╗"}
                    ,{"  ███╔═╝"}
                    ,{"██╔══╝  "}
                    ,{"███████╗"}
                    ,{"╚══════╝"}};

char *sprite_quattro[6]={{"  ██╗██╗"}
                        ,{" ██╔╝██║"}
                        ,{"██╔╝ ██║"}
                        ,{"███████║"}
                        ,{"╚════██║"}
                        ,{"     ╚═╝"}};

char *sprite_sei[6]={{" █████╗"}
                    ,{"██╔═══╝"}
                    ,{"██████╗"}
                    ,{"██╔══██╗"}
                    ,{"╚█████╔╝"}
                    ,{" ╚════╝ "}};

char *sprite_otto[6]={{" █████╗ "}
                     ,{"██╔══██╗"}
                     ,{"╚█████╔╝"}
                     ,{"██╔══██╗"}
                     ,{"╚█████╔╝"}
                     ,{" ╚════╝ "}};

char *sprite_dieci[6]={{"  ███╗   █████╗ "}
                      ,{" ████║  ██╔══██╗"}
                      ,{"██╔██║  ██║  ██║"}
                      ,{"╚═╝██║  ██║  ██║"}
                      ,{"███████╗╚█████╔╝"}
                      ,{"╚══════╝ ╚════╝ "}};

