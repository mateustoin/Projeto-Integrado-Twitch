from fastapi import FastAPI
import uvicorn
from datetime import datetime

app = FastAPI()

@app.get("/")
async def root():
    return {"message": "Hello World"}

@app.get("/bittoin")
async def bittoin():
    return {"message": "Bem vindos bem vindos!"}

@app.get("/temperatura/{temperatura}")
async def read_temp(temperatura):
    print(temperatura)
    now = datetime.now()
    return {"Temperatura": temperatura,
            "Timestamp": datetime.timestamp(now)}

if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=8000, debug=True)