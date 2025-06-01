FROM pwn.red/jail

COPY --from=ubuntu / /srv/

RUN mkdir /srv/app
COPY ./src/pwn /srv/app/run
COPY ./src/flag.txt /srv/app/flag.txt

ENV JAIL_TIME=30

