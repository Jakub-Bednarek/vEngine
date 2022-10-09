build_dir="build"
working_dir=$(shell pwd)
executable_name="vEngine"

color_red    := $(shell tput -Txterm setaf 1)
color_green  := $(shell tput -Txterm setaf 2)
color_yellow := $(shell tput -Txterm setaf 3)
color_clear 	 := $(shell tput -Txterm sgr0)

all: config build run

build: config
	@(echo "\n${color_green}Building ${executable_name}${color_clear}")
	@(echo "${color_yellow}Running make${color_clear}")
	@(cd ${build_dir} && make)

config:
	@(echo "\n${color_yellow}Running config${color_clear}")
	@if ! [ -d "./build" ]; then @mkdir ${build_dir}; fi
	@(cd ${build_dir} && cmake ..)

run:
	@(echo "\n${color_green}Running executable: ${executable_name}${color_clear}")
	@(./${build_dir}/${executable_name})
	@(echo "\n${color_green}Finished successfuly!${color_clear}")

clean:
	@(echo "\n${color_yellow}Running clean${color_clear}")
	@(echo "${color_green}Cleaning ${working_dir}/${build_dir}${color_clear}")
	@rm -rf ${build_dir}
	@echo "${color_green}Done${color_clear}"