import firebase_admin
from firebase_admin import credentials
from firebase_admin import firestore
from datetime import datetime

# Use a service account
cred = credentials.Certificate('chave/projeto-integrado-bittoin-firebase-adminsdk-rxd87-fb727914b2.json')
firebase_admin.initialize_app(cred)

db = firestore.client()

# Criação de dados em uma coleção

'''
doc_ref = db.collection(u'distancia').document()
doc_ref.set({
    u'distancia': 1,
    u'data': datetime.now(),
    u'tipo-sensor': u'Sensor Distância IR'
})
'''

# Leitura de dados de uma coleção

#distancia_ref = db.collection(u'distancia')
distancia_ref = db.collection(u'distancia').order_by(u'Timestamp')
docs = distancia_ref.stream()

for doc in docs:
    print(u'{} => {}'.format(doc.id, doc.to_dict()))