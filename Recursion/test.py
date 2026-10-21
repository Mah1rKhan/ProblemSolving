import math

def sigmoid(x):
    return 1 / (1 + math.exp(-x))


# Inputs and target
O1, O2, O3 = 0, 1, 0
target = 1
lr = 0.9

# Initial weights
w14, w15 = 0.2, -0.3
w24, w25 = 0.4, 0.1
w34, w35 = -0.5, 0.2
w46, w56 = -0.3, -0.2

# Initial biases
theta4, theta5, theta6 = -0.4, 0.2, 0.1


for step in range(1, 3):
    print(f"\n{'=' * 15} ITERATION {step} {'=' * 15}")

    # 1. Forward propagation
    I4 = O1*w14 + O2*w24 + O3*w34 + theta4
    O4 = sigmoid(I4)

    I5 = O1*w15 + O2*w25 + O3*w35 + theta5
    O5 = sigmoid(I5)

    I6 = O4*w46 + O5*w56 + theta6
    O6 = sigmoid(I6)

    print("\nForward propagation:")
    print(f"O1 = {O1:.6f}")
    print(f"O2 = {O2:.6f}")
    print(f"O3 = {O3:.6f}")
    print(f"I4 = {I4:.6f}, O4 = {O4:.6f}")
    print(f"I5 = {I5:.6f}, O5 = {O5:.6f}")
    print(f"I6 = {I6:.6f}, O6 = {O6:.6f}")

    print(f"\nTarget = {target}")
    print(f"Prediction = {O6:.6f}")
    print(f"Prediction error (target - output) = {target - O6:.6f}")

    # 2. Backpropagation
    delta6 = O6 * (1 - O6) * (target - O6)

    # Use old output-layer weights for hidden deltas
    delta4 = O4 * (1 - O4) * delta6 * w46
    delta5 = O5 * (1 - O5) * delta6 * w56

    print("\nError terms:")
    print(f"delta4 = {delta4:.6f}")
    print(f"delta5 = {delta5:.6f}")
    print(f"delta6 = {delta6:.6f}")

    # 3. Update weights
    w14 += lr * delta4 * O1
    w24 += lr * delta4 * O2
    w34 += lr * delta4 * O3

    w15 += lr * delta5 * O1
    w25 += lr * delta5 * O2
    w35 += lr * delta5 * O3

    w46 += lr * delta6 * O4
    w56 += lr * delta6 * O5

    # 4. Update biases
    theta4 += lr * delta4
    theta5 += lr * delta5
    theta6 += lr * delta6

    # 5. Print updated parameters
    print("\nUpdated weights:")
    for name, value in [
        ("w14", w14), ("w15", w15),
        ("w24", w24), ("w25", w25),
        ("w34", w34), ("w35", w35),
        ("w46", w46), ("w56", w56)
    ]:
        print(f"{name} = {value:.6f}")

    print("\nUpdated biases:")
    print(f"theta4 = {theta4:.6f}")
    print(f"theta5 = {theta5:.6f}")
    print(f"theta6 = {theta6:.6f}")