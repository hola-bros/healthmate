from fastapi import FastAPI, Depends, HTTPException, status
from pydantic import BaseModel, EmailStr
from passlib.context import CryptContext
from datetime import datetime
import uuid

# Configuración de Seguridad
pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")
app = FastAPI(title="HealthMate ")


# --- MODELOS AUTOMÁTICOS
class UsuarioCreate(BaseModel):
    email: EmailStr
    password: str


class UsuarioResponse(BaseModel):
    id: uuid.UUID
    email: str
    fecha_registro: datetime

    class Config:
        from_attributes = True


# --- LÓGICA DE SEGURIDAD ---
def obtener_password_hash(password):
    return pwd_context.hash(password)


# --- ENDPOINTS ---
@app.post("/usuarios/", response_model=UsuarioResponse, status_code=status.HTTP_201_CREATED)
async def crear_usuario(usuario: UsuarioCreate):
    # Simulación de guardado (Aquí conectarías con tu lógica de DB)
    hashed_password = obtener_password_hash(usuario.password)


    nuevo_usuario = {
        "id": uuid.uuid4(),
        "email": usuario.email,
        "password_segura": hashed_password,
        "fecha_registro": datetime.now()
    }

    print(f"DEBUG: Guardando en Postgres con hash: {hashed_password}")
    return nuevo_usuario


@app.get("/")
def inicio():
    return {"mensaje": "tilingo, tu asistente de salud personal. "}