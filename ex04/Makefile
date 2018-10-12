SRCFILES = ft_last \
			print_time \
			ft_strcmp \
			fill_line \
			print_time_begins \
			size_line \

TARGET = ft_last

all:
	gcc -o $(TARGET) $(addsuffix .c, $(SRCFILES)) 

clean:
	rm -f $(addsuffix .o, $(SRCFILES))
	
fclean: clean
	rm -f $(TARGET)
	
re: fclean all
