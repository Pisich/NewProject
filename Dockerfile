FROM alpine:3.12

RUN apk add figlet && apk add basic-tools && apk add git

CMD git clone https://github.com/Pisich/PisiChBank ; cd PisiChBank/ ; gcc -o PisiChBank main.c ; ./PisichBank
