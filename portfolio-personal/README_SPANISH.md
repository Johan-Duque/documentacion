# Portafolio

Este es un sitio web de portafolio personal que muestra mis habilidades, proyectos y experiencia como desarrollador Front-End. El sitio web está construido con tecnologías web modernas para proporcionar una experiencia de usuario receptiva y atractiva.

## Características

-   **Arquitectura Basada en Componentes:** Construido con React, la interfaz de usuario se divide en componentes reutilizables y modulares.
-   **TypeScript:** El proyecto está escrito en TypeScript, proporcionando tipado estático para una mejor calidad y mantenibilidad del código.
-   **Estilos:** Utiliza Módulos CSS para estilos con alcance a componentes, y estilos globales para el tema general.
-   **Soporte Multilenguaje:** El sitio web soporta tanto inglés como español, con traducciones gestionadas a través de un Context de React personalizado.
-   **Datos desde JSON:** El contenido de las secciones Acerca de, Experiencia, Proyectos y Tecnologías se obtiene de archivos JSON locales, lo que facilita su actualización.
-   **Carga Perezosa (Lazy Loading):** Las secciones se cargan de forma perezosa para mejorar el tiempo de carga inicial.
-   **Vite:** Una herramienta de construcción rápida que proporciona una experiencia de desarrollo ultrarrápida.

## Tecnologías Utilizadas

-   **React:** Una biblioteca de JavaScript para construir interfaces de usuario.
-   **TypeScript:** Un superconjunto tipado de JavaScript que compila a JavaScript plano.
-   **Vite:** Una herramienta de construcción rápida que proporciona una experiencia de desarrollo ultrarrápida.
-   **HTML5 y CSS3:** Los lenguajes estándar de marcado y estilo para crear páginas web.

## Librerías Utilizadas

-   `react`: Librería principal de React.
-   `react-dom`: Paquete de React para trabajar con el DOM.
-   `react-icons`: Una colección de iconos SVG populares como componentes de React.

## Empezando

Para obtener una copia local y ponerla en marcha, sigue estos sencillos pasos.

### Prerrequisitos

-   npm
    ```sh
    npm install npm@latest -g
    ```

### Instalación

1.  Clona el repositorio
    ```sh
    git clone https://github.com/tu_usuario_/Nombre-Del-Proyecto.git
    ```
2.  Instala los paquetes de NPM
    ```sh
    npm install
    ```
3.  Ejecuta el servidor de desarrollo
    ```sh
    npm run dev
    ```

## Estructura de la Aplicación

El proyecto sigue una arquitectura basada en componentes, organizando el código en piezas reutilizables y modulares.

```
Portfolio/
├── public/                 # Activos estáticos (imágenes, favicon)
├── src/                    # Código fuente principal de la aplicación
│   ├── App.tsx             # Componente principal de la aplicación
│   ├── index.css           # Estilos globales
│   ├── main.tsx            # Punto de entrada de la aplicación
│   ├── Components/         # Componentes de interfaz de usuario reutilizables
│   │   ├── Carousel/
│   │   ├── Error/
│   │   ├── Hero/
│   │   ├── Loading/
│   │   ├── Navigation/
│   │   └── ProjectCard/
│   ├── Contexts/           # Contextos de React para la gestión del estado global
│   │   └── LanguageContext.tsx
│   ├── Hooks/              # Hooks de React personalizados para lógica reutilizable
│   │   └── index.ts
│   ├── jsons/              # Archivos JSON con los datos de la aplicación
│   │   ├── about.json
│   │   ├── experience.json
│   │   ├── projects.json
│   │   └── technologies.json
│   ├── libs/               # Funciones de utilidad
│   │   └── index.ts
│   └── Sections/           # Secciones principales del portafolio
│       ├── About/
│       ├── Experience/
│       ├── Footer/
│       ├── Home/
│       ├── Projects/
│       └── Technologies/
├── .gitignore              # Especifica archivos no rastreados intencionalmente para ignorar
├── index.html              # Archivo HTML principal
├── package.json            # Metadatos y dependencias del proyecto
└── vite.config.ts          # Configuración de Vite
```
