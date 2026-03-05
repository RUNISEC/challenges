FROM docker.io/nginx:alpine

RUN rm -rf /usr/share/nginx/html/*

COPY ./src/index.html /usr/share/nginx/html/index.html
COPY ./src/app.js /usr/share/nginx/html/app.js

EXPOSE 80

CMD ["nginx", "-g", "daemon off;"]
