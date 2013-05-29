## Makefile for make_my in /u/all/collio_v/rendu/piscine/Jour_13/cat
##
## Made by vincent colliot
## Login   <collio_v@epitech.net>
##
## Started on Thu Oct 25 22:06:03 2012 vincent colliot
## Last update Wed May 29 17:20:56 2013 vincent colliot
##

NAME    = rt

RM      = rm -f

FO	=./

SRCF	=$(FO)src/

######################

X_LIB	=$(SRCF)x_lib/

S_LIB	=$(SRCF)s_lib/
LIB	=$(S_LIB)s_lenth.c\
	$(S_LIB)s_match.c\
	$(S_LIB)s_token.c\
	$(S_LIB)s_xml.c\
	$(S_LIB)s_alloc.c\
	$(X_LIB)xmalloc.c\

F_GTN	=$(SRCF)get/
GTN	=$(F_GTN)get_next_line.c\

F_MAIN	=$(SRCF)main/
MAIN	=$(F_MAIN)main.c\

##     CLASSE       ##
#		     #
FCLASSE	=$(SRCF)classe/
#		     #
###### DISPLAY #######

F_DPRIV	=$(FCLASSE)display/private/

DU_FINIT=$(F_DPRIV)init/
DU_INIT	=$(DU_FINIT)call_init.c\

DPRIV	=$(DU_INIT)\

##

F_DPUB	=$(FCLASSE)display/public/

DP_FSCAN=$(F_DPUB)scan/
DP_SCAN	=$(DP_FSCAN)scan.c\

DPUB	=$(DP_SCAN)\

##

DISPLAY	=$(DPRIV)\
	$(DPUB)

######  LIGHT  #######

###### OBJECTS #######




######################
#		     #
#		     #
######################

SRC     =$(MAIN)\
	$(GTN)\
	$(LIB)\
	$(DISPLAY)\

######################

INC	=-I $(FO)include/ -I include/classe

CFLAGS	= -Wall -Wextra $(INC)

DOTO    = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	@ $(CC) $(CFLAGS) -c -o $@ $< \
	&& echo -e "[\e[35mGCC\e[m]\e[33m" $< "\e[m=>\e[36m" $@ "\e[m" \
	|| echo -e "[\e[35mGCC\e[m]\e[33m" $< "\e[m=>" "\e[31mERROR\e[m"

$(NAME): $(DOTO)
	@ cc -o $(NAME) $(DOTO) $(CFLAGS)
	@ echo -e "\e[32m"$(NAME)"\e[m" "is alive !"
	@ echo -e "\e[37mActivated CFLAGS :\e[m" $(CFLAGS)

debug:
	cc -o $(NAME) $(SRC) $(INC) -g3

clean:
	$(RM) $(DOTO)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean
