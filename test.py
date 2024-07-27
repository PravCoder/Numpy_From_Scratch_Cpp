import numpy as np

# Create a 2x3 matrix
matrix = np.array([[1, 2, 3],
                   [4, 5, 6]])
print("Original Matrix:")
print(matrix)


# Reshape to 3x2
reshaped_matrix = matrix.reshape(3, 2)
print("\nReshaped Matrix (3x2):")
print(reshaped_matrix)
