<div align="center">
  <img src="docs/assets/utopiapm-logo.svg" width="400">

# Utopia Package Manager

📂 Universal Package Manager for Utopia Linux.




[![Performance](https://img.shields.io/badge/⚡️-blazing_fast-blue?style=for-the-badge)]()
[![License: AGPL-3.0](https://img.shields.io/badge/license-AGPL--3.0-blue?style=for-the-badge)](https://codeberg.org/titago/UtopiaPM/src/branch/main/LICENSE)

  </div>

  ---

## 📋 Table of Contents

1. [Features](#features)
2. [Status & Roadmap](#status--roadmap)
3. [Installation](#installation)
4. [Contributing](#contributing)
5. [License](#license)

  ---

## ✨ Features <a id="features"></a>

- 🔹 **Intuitive CLI** — context‑aware help and suggestions.
- ⚡ **Blazing performance** — instant package installation.
- 🎨 **Clean output** — colorized, structured, and easy in use.
- 🔒 **Memory-Safe** — all code tested.
- 🌐 **Cross‑platform** — support almost all Linux distributions and architectures.

  ---

## 📊 Status & Roadmap <a id="status--roadmap"></a>

| Feature               | Status | Notes                           |
|-----------------------|:------:|---------------------------------|
| Arguments             |   ✓    | All arguments added and testing |
| Package downloading   |   ✓    | Testing downloading...          |
| Package install (bin) |   ✓    | Testing installation            |
| Package compiling     |   ✓    | Testing compiling...            |
| Package removing      |   ✗    | Add soon....                    |
| Package update        |   ✗    | Planning                        |
| Package verification  |   ✓    | Testing                         |
| Repositories          |   ✗    | Planning...                     |
| Mirrors               |   ✗    | Planning....                    |
| Configuration         |   ✗    | Add soon....                    |

  ---

## 🚀 Installation <a id="installation"></a>

### 🏗️ Building from source

#### Install clang (if missing)

#### Clone repo
  ```fish
  git clone https://codeberg.org/titago/UtopiaPM.git
  ```
  ```fish
  cd UtopiaPM && mkdir build && cd build
  ```
#### Compiling
  ```fish
  cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr ..    
  ```
  ```fish
  make && make install
  ```
  ---

## 🤝 Contributing <a id="contributing"></a>

We welcome contributions! Please:

      ⭐️ Star the repo

      🍴 Fork & create a branch (feature/xyz)

      📝 Add tests & documentation

      🔀 Open a Pull Request

---

## 📄 License <a id="license"></a>

    This project is licensed under the AGPL-3.0 License.
    See LICENSE for details.
