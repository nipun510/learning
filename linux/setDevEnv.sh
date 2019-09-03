echo "Installing node"
sudo apt-get install curl python-software-properties
curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
sudo apt-get install nodejs


echo "Installing Mongodb"
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv 9DA31620334BD75D9DCB49F368818C72E52529D4
echo "deb http://repo.mongodb.org/apt/debian jessie/mongodb-org/4.0 main" | sudo tee /etc/apt/sources.list.d/mongodb-org-4.0.list
sudo apt-get update
sudo apt-get install -y mongodb-org
sudo systemctl start mongod


echo "Fetching code and starting node webserver"
git clone https://github.com/nipun510/nodeJs.git
cd nodeJs
npm install
npm start

echo "visit http://localhost"


echo "PS1='\e[0;35m\u\e[0m@\e[0;36m\h\e[0m:[\e[0;32m$PWD\e[0m]\n'" >> ~/.bashrc
