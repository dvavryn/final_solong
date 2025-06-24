# rm ./a.out
# cc map.c floodfill.c ../libft/libft.a -g
# cc floodfill.c ../libft/libft.a 
# ./a.outq
# cc main.c create_delete.c handler.c map.c floodfill.c funcheck.c -L../libft -lft -L./mlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o solong -g
cc main.c create_delete.c handler.c map.c floodfill.c funcheck.c -L../libft -lft -L/usr/lib -lmlx -lXext -lX11 -lm -lz -o solong -g
./solong map/map.ber
