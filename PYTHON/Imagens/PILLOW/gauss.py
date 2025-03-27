from PIL import Image, ImageFilter

# Carregar a imagem
img = Image.open("imagem.jpg")

# Aplicar desfoque gaussiano (raio 5)
img_blur = img.filter(ImageFilter.GaussianBlur(radius=5))

# Exibir a imagem original e a desfocada
img.show()
img_blur.show()

# Salvar a imagem desfocada
img_blur.save("imagem_desfocada.jpg")
