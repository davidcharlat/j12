SRCFILES = ft_tail \
		   print_file \
		   print_err
TARGET = ft_tail

all:
	gcc -o $(TARGET) $(addsuffix .c, $(SRCFILES)) libft.a
		
clean:
	rm -f $(addsuffix .o, $(SRCFILES))
	
fclean: clean
	rm -f $(TARGET)
	
re: fclean all
