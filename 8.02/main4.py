password = input("Введите пароль для проверки: ")
errors = []
special_chars = "!@#$%^&*"

if len(password) < 8:
    errors.append("❌ Длина пароля меньше 8 символов")
if not any(c.isdigit() for c in password):
    errors.append("❌ Нет цифр")
if not any(c.isupper() for c in password):
    errors.append("❌ Нет заглавных букв")
if not any(c.islower() for c in password):
    errors.append("❌ Нет строчных букв")
if not any(c in special_chars for c in password):
    errors.append(f"❌ Нет специальных символов ({special_chars})")

if errors:
    print("⚠️ Пароль не соответствует требованиям безопасности:")
    for error in errors:
        print(f"  {error}")
else:
    print("✅ Пароль надежный!")