FROM opensuse
COPY src/  /opt/bellServer
WORKDIR /opt/bellServer

EXPOSE 8080
EXPOSE 8081

RUN zypper refresh
RUN zypper in -y nodejs npm
RUN npm install express util ws
ENTRYPOINT ["/opt/bellServer/start.sh"]
