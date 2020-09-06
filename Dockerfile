FROM alpine:3.12

RUN apk add figlet && apk add build-base

CMD ["git clone https://github.com/Pisich/PisiChBank", "cd PisiChBank", "gcc -o main.c PisiChBank", "./PisichBank.exe"]
