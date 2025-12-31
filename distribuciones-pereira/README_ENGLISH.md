# Distribuciones Pereira

Welcome to the official repository for the Distribuciones Pereira website! This project is a modern web application built with **React**, **TypeScript**, and **Vite**.

## Key Features

- **Modern UI:** Built with **React 19** for a dynamic and reactive user interface.
- **Fast Development:** Powered by **Vite** as the build tool, offering a highly efficient development server.
- **Static Typing:** Developed with **TypeScript** for robust, readable, and maintainable code, minimizing runtime errors.
- **Efficient Routing:** Managed by **React Router DOM v7**, enabling declarative navigation across all sections.
- **Powerful Form Validation:** Implemented using **React Hook Form** for efficient state management and **Zod** for secure, schema-based validation.
- **Reusable Components:** A component-based architecture that promotes reusability and design consistency throughout the app.
- **Performance Optimization (Lazy Loading):** Images and pages are lazy-loaded to optimize performance and initial load speed.
- **Error Handling:** Implementation of `Error Boundaries` to catch and handle errors at the page level, preventing full application crashes.
- **Code Quality:** Uses **ESLint** to enforce a consistent coding style and detect potential issues early.

## Available Scripts

In the `package.json` file, you will find the following scripts:

- `npm run dev`: Starts the Vite development server.
- `npm run build`: Compiles and optimizes the application for production in the `dist/` folder.
- `npm run lint`: Runs ESLint to analyze code for errors and styling issues.
- `npm run preview`: Launches a local server to preview the production build.
- `npm run deploy`: Deploys the application to GitHub Pages.

## Key Dependencies

### Production

- **`react`**: Core library for building the user interface.
- **`react-dom`**: Provides DOM-specific methods for React.
- **`react-router-dom`**: For client-side routing.
- **`react-hook-form`**: For form state management.
- **`@hookform/resolvers`**: To integrate Zod with React Hook Form.
- **`zod`**: For schema-based validation.
- **`@emailjs/browser`**: For sending emails directly from the client.
- **`react-icons`**: Provides a wide variety of icons as React components.
- **`react-imask`**: For creating input masks.

### Development

- **`vite`**: Build tool and development server.
- **`@vitejs/plugin-react`**: Official Vite plugin for React projects.
- **`typescript`**: JavaScript superset with static typing.
- **`eslint`**: Static code analysis tool.
- **`gh-pages`**: For easy deployment to GitHub Pages.

## Project Structure

The project follows an organized structure to facilitate navigation and maintenance:

```
/src
|-- /assets
|-- /Components  # Componentes reutilizables
|-- /Context     # Contexto de React
|-- /Hooks       # Hooks personalizados
|-- /Pages       # Componentes de página
|-- /Types       # Tipos y esquemas de TypeScript
|-- /Services    # Servicios usados
|-- App.tsx
|-- main.tsx
```
