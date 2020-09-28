from fastapi import FastAPI
import uvicorn
from datetime import datetime

# Imports relacionados a conexão com Firestore (Firebase)
import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore

from fastapi.middleware.cors import CORSMiddleware

# Use a service account
cred = credentials.Certificate('chave/projeto-integrado-bittoin-firebase-adminsdk-rxd87-fb727914b2.json')
firebase_admin.initialize_app(cred)

db = firestore.client()

app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

@app.get("/")
async def root():
    return {"message": "Boas vindas à API de coleta de dados da ESP32!"}

@app.get("/distancia/{distancia}")
async def read_dist(distancia):

    now = datetime.now()
    data = {u"Distancia": distancia,
            u"Timestamp": datetime.timestamp(now)}
    
    doc_ref = db.collection(u'distancia').document()
    doc_ref.set(data)
    
    return data

@app.get("/dados/distancia")
async def return_dist():
    distancia_ref = db.collection(u'distancia').order_by(u'Timestamp')
    docs = distancia_ref.stream()
    
    lista = []
    for doc in docs:
        #print(u'{} => {}'.format(doc.id, doc.to_dict()))
        lista.append(doc.to_dict())
    
    return lista