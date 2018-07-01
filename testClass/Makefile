CC = g++
out_dir = ./out
src_dir = ./src

target = $(out_dir)/main

objects = $(src_dir)/Rectangle.o \
		$(src_dir)/Triangle.o \
		$(src_dir)/Shape.o \
		$(src_dir)/main.o

$(target):$(objects)
	@rm -rf $(out_dir)
	@mkdir $(out_dir)
	$(CC) -o $(target) $(objects)
	
clean:
	rm -rf $(objects) \
	rm -rf $(out_dir)
