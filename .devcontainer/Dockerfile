FROM ubuntu:latest
RUN apt-get update
RUN apt-get install -y apt-utils build-essential sudo vim git cppcheck cmake python3-pip wget googletest lcov 
RUN pip3 install cpplint gcovr
RUN cd /usr/src/googletest && mkdir -p build && cd build && cmake CMAKE_INSTALL_PREFIX:PATH=/usr .. && make && make install

# RUN useradd -m docker && echo "docker:docker" | chpasswd && adduser docker sudo
# USER docker
# WORKDIR /home/docker

COPY . .
#RUN chown docker * -r
