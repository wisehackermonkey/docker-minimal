# go docker file
FROM scratch
ADD go/hello-world /
CMD ["/hello-world"]