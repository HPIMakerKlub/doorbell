FROM opensuse
COPY src/  /opt/bellServer
WORKDIR /opt/bellServer
#RUN chmod 775 start.sh
#ADD .npmrc .
EXPOSE 8080
EXPOSE 8081
#ADD opt/containerbuddy/ /opt/containerbuddy/
#RUN  npm install --production && npm install --production -g json && npm install --production -g bunyan
RUN zypper refresh
RUN zypper in -y nodejs npm
RUN npm install express util ws
ENTRYPOINT ["/opt/bellServer/start.sh"]
