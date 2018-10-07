SRCFILES = ft_display_file 
TARGET = ft_display_file 

all:
	gcc -o $(TARGET) $(addsuffix .c, $(SRCFILES))
		
clean:
	rm -f $(addsuffix .o, $(SRCFILES))
	
fclean: clean
	rm -f $(TARGET)
	
re: fclean all
