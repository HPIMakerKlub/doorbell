var express = require("express");
var app = express();
var util = require("util");

var WebSocketServer = require('ws').Server
  , wss = new WebSocketServer({ port: 8081 });

wss.broadcast = function broadcast(data) {
  wss.clients.forEach(function each(client) {
    client.send(data);
  });
};


wss.on('connection', function connection(ws) {
console.log("lcient connected!");
  ws.send("hey!");
  ws.on('message', function incoming(message) {
    console.log('received: %s', message);
  });
});

app.use("/",express.static("client",{dotfiles:"deny",index:false}));

app.get("/bell",function(req,res){
	console.log("bell");
	res.status(200);
        res.write("ok thats the bell");
        res.end();
	wss.broadcast("bell");
});
app.listen(8080);
