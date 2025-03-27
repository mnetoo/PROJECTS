import cv2

# Carregar a imagem
img = cv2.imread("imagem.jpg")

# Aplicar desfoque gaussiano (kernel 15x15)
img_blur = cv2.GaussianBlur(img, (15, 15), 0)

# Exibir a imagem original e a desfocada
cv2.imshow("Original", img)
cv2.imshow("Desfoque Gaussiano", img_blur)

cv2.waitKey(0)  # Espera pressionar uma tecla
cv2.destroyAllWindows()  # Fecha as janelas
