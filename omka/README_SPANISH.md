# OMKA - Catálogo de Productos y Sitio Corporativo

Este proyecto es un sitio web corporativo moderno desarrollado con Next.js, React y TypeScript, diseñado para servir como un catálogo de productos, blog y centro de información para la empresa OMKA.

## Stack Tecnológico

- **Framework:** [Next.js](https://nextjs.org/) (con App Router)
- **Lenguaje:** [TypeScript](https://www.typescriptlang.org/)
- **UI:** [React](https://reactjs.org/)
- **Estilos:** [Tailwind CSS](https://tailwindcss.com/)
- **Manejo de Datos:** Archivos JSON locales como sistema de contenido (Headless CMS).
- **Mapas:** [Leaflet.js](https://leafletjs.com/) para visualización de distribuidores.
- **Imágenes:** Alojadas en [Cloudinary](https://cloudinary.com/).

## Arquitectura del Proyecto

La aplicación utiliza un enfoque de "CMS basado en Git", donde todo el contenido (productos, publicaciones de blog, clientes) se almacena en archivos JSON dentro del directorio `data/jsons/`.

- **`src/app/`**: Contiene la estructura de rutas y las páginas de la aplicación, utilizando el App Router de Next.js. Las carpetas aquí se mapean directamente a las URL del sitio.
- **`data/jsons/`**: Actúa como la "base de datos" del proyecto. Los componentes del servidor leen estos archivos para obtener los datos que se mostrarán.
- **`src/libs/serverData.tsx`**: Un componente clave que exporta la función `getLocalData`. Esta utilidad se ejecuta exclusivamente en el servidor (gracias al paquete `server-only`) para leer y parsear los archivos JSON del sistema de archivos.
- **`next.config.ts`**: Configuración de Next.js, que incluye la configuración del dominio de imágenes remoto para Cloudinary.

## Puesta en Marcha

Para ejecutar este proyecto en un entorno de desarrollo local, sigue estos pasos:

1.  **Clonar el repositorio**
    ```bash
    git clone <URL_DEL_REPOSITORIO>
    cd OMKA
    ```

2.  **Instalar dependencias**
    Se utiliza `npm` como gestor de paquetes.
    ```bash
    npm install
    ```

3.  **Ejecutar el servidor de desarrollo**
    ```bash
    npm run dev
    ```
    Abre [http://localhost:3000](http://localhost:3000) en tu navegador para ver el resultado.

## Scripts Disponibles

En el archivo `package.json`, encontrarás los siguientes scripts:

- **`npm run dev`**: Inicia la aplicación en modo de desarrollo.
- **`npm run build`**: Compila la aplicación para producción.
- **`npm run start`**: Inicia un servidor de producción con la versión compilada.
- **`npm run lint`**: Ejecuta ESLint para analizar el código en busca de problemas.

## Fuentes de Datos Externas

Este proyecto depende de un servicio externo para el alojamiento de imágenes:

- **Cloudinary**: Todas las imágenes de productos y contenido son servidas desde Cloudinary. La configuración se encuentra en `next.config.ts`. Para un funcionamiento completo, se necesitaría acceso a la cuenta de Cloudinary correspondiente.