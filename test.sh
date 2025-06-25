clear
# norminette ./*.c | grep Error
# rm ./a.out
# cc map.c floodfill.c ../libft/libft.a -g
# cc floodfill.c ../libft/libft.a 
# ./a.outq
cc check_file.c copy_split.c check_map.c create_delete.c floodfill.c handler.c main.c map.c move.c utils.c -L../libft -lft -L./mlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o solong -g
# cc main.c create_delete.c handler.c map.c floodfill.c funcheck.c -L../libft -lft -L/usr/lib -lmlx -lXext -lX11 -lm -lz -o solong -g
# funcheck -ac ./solong map/map.ber
# ./solong map/map_cpy.ber
./solong map/map.ber