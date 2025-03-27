from PIL import Image

img = Image.open("imagem.jpg")  # Abrir a imagem
img.show()  # Exibir a imagem

img_resized = img.resize((350, 200))  # Novo tamanho (largura, altura)
img_resized.show()

img_rotated = img.rotate(45)  # Rotaciona 45 graus
img_rotated.show()

img_gray = img.convert("L")  # Converte para tons de cinza
img_gray.show()

img_gray.save("imagem_cinza.jpg")  # Salva a imagem em tons de cinza