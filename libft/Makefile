#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 22:37:03 by ciglesia          #+#    #+#              #
#    Updated: 2020/09/13 23:41:04 by ciglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a
DIRSRC		=	.
DIROBJ		=	./depo/
INCLUDE		=	./include/
SUB_MAKE	=	./ft_printf/
INC_LIB		=	-L$(SUB_MAKE) -lftprintf
SRC			=	ft_memset.c ft_abs.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_atoi_protected.c ft_do_op.c ft_fprime.c ft_pgcd.c ft_swap_bits.c ft_ulstr.c ft_sort_list.c ft_strrev.c ft_itoa_base.c ft_fstrjoin.c ft_strndup.c get_next_line.c ft_countchr.c ft_sqrt.c ft_chgchr.c ft_fillstr.c ft_cpyxchr.c ft_vstrdup.c ft_freesv.c free_split.c exceeds_int.c ft_puterr.c get_next_line2.c ft_lstnew2.c ft_scmp.c ft_repet.c ft_repet_fd.c ft_putnbr_max.c ft_isint.c ft_mod.c file_name.c ft_split.c ft_decompose.c ft_itersplit.c ft_coordsplit.c ft_sizei.c ft_strcmpn.c

OAUX		=	$(SRC:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.c=.d)
OBJS		=	$(OAUX:.c=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e

%.o		:		../$(DIRSRC)/%.c
				$(CC) $(CFLAGS) -I $(INCLUDE) -MMD -o $@ -c $<

$(NAME)	:		printf $(OBJS)
				@$(ECHO) '\t*@@@@*    *@@@@**@@@***@@m*@@@***@@@@@@**@@**@@@'
				@$(ECHO)   '\t  @@        @@    @@    @@  @@    *@@*   @@   *@'
				@$(ECHO)   '\t  @@        @@    @@    @@  @@   @       @@'
				@$(ECHO)   '\t  @@        @@    @@***@mm  @@**@@       !@'
				@$(ECHO)   '\t  @!     m  @!    @!    *@  !@   @       !@'
				@$(ECHO)   '\t  @!    :@  @!    !!    m@  !@           !@'
				@$(ECHO)   '\t  !!     !  !!    !:    *!  !!           !@'
				@$(ECHO)   '\t  !:    !!  :!    !:    !!  :!           !!'
				@$(ECHO) '\t: :: !: : :!: : : !: : : ::!: :        : :!::'
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				@ar -M <build-libft.mri
				@$(ECHO) '> Compiled'

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(DEPS))
				@(cd $(SUB_MAKE) && $(MAKE) clean)
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				@(cd $(SUB_MAKE) && $(MAKE) fclean)
				@$(RM) $(NAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

printf	:
				@(cd $(SUB_MAKE) && $(MAKE))
				@$(RM) $(NAME)

.PHONY	:		all clean re

-include $(DEPS)
