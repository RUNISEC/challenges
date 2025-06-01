FROM docker.io/nginx:alpine

# Remove default nginx content
RUN rm -rf /usr/share/nginx/html/*

COPY ./src/index.html /usr/share/nginx/html/index.html
COPY ./src/robots.txt /usr/share/nginx/html/robots.txt

EXPOSE 80

CMD ["nginx", "-g", "daemon off;"]
