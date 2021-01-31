FROM scratch
COPY hello /
# [gcc - Docker Hub](https://hub.docker.com/_/gcc/)
CMD ["/hello"]
# FROM docker/whalesay:latest
# LABEL Name=dockerminimal Version=0.0.1
# RUN apt-get -y update && apt-get install -y fortunes
# CMD ["sh", "-c", "/usr/games/fortune -a | cowsay"]
