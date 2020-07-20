if [ "$1" = 'W' ]
then
    flags="-Wall -Werror -Wextra"
fi
gcc -g $flags -fsanitize=address  -I . -I ft_printf/ ft_printf/*.c main.c
