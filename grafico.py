import requests
from matplotlib import pyplot as plt

plt.style.use('seaborn')

req = requests.get('http://127.0.0.1:8000/dados/distancia')
dados = req.json()

eixo_x = []
eixo_y = []

for dado in range(500, len(dados)):
    #eixo_x.append(dados[dado]['Timestamp'])
    eixo_x.append(dado - 500)
    eixo_y.append(dados[dado]['Distancia'])

# Eixo_x, Eixo_y
plt.plot(eixo_x, eixo_y)
plt.show()