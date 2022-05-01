// const exp=require('express')
// const app=exp();
// const my_path=require('path')
// app.listen(3500,()=>console.log('http://localhost:3500'))

// const op={
//     root: my_path.join(__dirname)
// }
// //app.use(exp.json())
// app.get('/',(req,res)=>{
//     res.sendFile("index.html",op,(err)=>{if(err){throw err}
// else console.log('send')})
// })
// 
const Net = require('net');
// The port on which the server is listening.
const port =80;

// Use net.createServer() in your code. This is just for illustration purpose.
// Create a new TCP server.
const server = new Net.Server();
// The server listens to a socket for a client to make a connection request.
// Think of a socket as an end point.
server.listen(port, function() {
   
    console.log(`Server listening for connection requests on socket localhost:${port}`);
});

// When a client requests a connection with the server, the server creates a new
// socket dedicated to that client.
server.on('connection', function(socket) {
    console.log('A new connection has been established.');
    

    // Now that a TCP connection has been established, the server can send data to
    // the client by writing to its socket.
    socket.write('Hello, client.');

    // The server can also receive data from the client by reading from its socket.
    socket.on('data', function(chunk) {
        parseBuffer("asdfg");
        console.log(`Data received from client: ${chunk.toString()}.`);
    });

    // When the client requests to end the TCP connection with the server, the server
    // ends the connection.
    socket.on('end', function() {
        console.log('Closing connection with the client');
    });

    // Don't forget to catch error, for your own sake.
    socket.on('error', function(err) {
        console.log(`Error: ${err}`);
    });
});

const parseBuffer=(buffer)=>{
let message={};
message.type= parseInt((String)(buffer[1]));
if(message.type==1)
   message.status = parseInt(buffer[2]);
else
{
    message.distance= parseInt(buffer[2]);
	message.angle= parseInt(buffer[6]);
	message.speed= parseInt(buffer[10]);
}
console.log("message",message);
}

