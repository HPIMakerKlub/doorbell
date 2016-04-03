# doorbell

SERVER:
Um den fertigen Container zu starten folgendes Kommando verwenden:

docker run -d --name bell -p 8080:8080 -p 8081:8081 jakobbraun/hpi-makerklub-bell 


Um den Container selbst zu erstellen:
sudo docker build -t jakobbraun/hpi-makerklub-bell .
