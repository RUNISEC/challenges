FROM docker.io/nginx:alpine

RUN rm -rf /usr/share/nginx/html/* /etc/nginx/conf.d/default.conf

COPY ./src/nginx.conf /etc/nginx/conf.d/default.conf
COPY ./src/index.html /usr/share/nginx/html/index.html

EXPOSE 80

CMD ["nginx", "-g", "daemon off;"]
