module.exports = function(grunt) {

    grunt.initConfig({
        pkg: grunt.file.readJSON('package.json'),

        svgstore: {
            icons: {
                options: {
                    prefix : 'icon-',
                },
                files: {
                    '../themes/bookbox_ui/images/svg-icons-sprite.svg': ['../themes/bookbox_ui/icons-svg/*.svg']
                },
            },
            logos: {
                files: {
                    '../themes/bookbox_ui/images/svg-images-sprite.svg': 'img-svg/*.svg'
                }
            }
        },
    
        less: {
            development: {
                options: {
                    paths: ['less'],
                    compress: false,
                    cleancss: true,
                    dumpLineNumbers: 'comments'
                },
                files: {
                    '../themes/bookbox_ui/css/style.css': '../themes/bookbox_ui/less/style.less'
                }
            }
        },

        bake: {
            your_target: {
                options: {
                    // Task-specific options go here.
                },

                files: {
                    // files go here, like so:
                    "../themes/bookbox_ui/templates/page.tpl.php": "../themes/bookbox_ui/_templates-src/page.tpl.php",
                    "../themes/bookbox_ui/templates/page--type-book.tpl.php": "../themes/bookbox_ui/_templates-src/page--type-book.tpl.php"
                }
            }
        },

        watch: {
            grunt: {
                files: ['Gruntfile.js']
            },

            svgstore: {
                files: [
                    '../themes/bookbox_ui/icons-svg/*.svg',
                    '../themes/bookbox_ui/img-svg/*.svg'
                ],
                tasks: ['svgstore']
            },

            less: {
                files: [
                    '../themes/bookbox_ui/less/**/*.less',
                    '../themes/bookbox_ui/less/**/**/*.less'
                ],
                tasks: ['less', 'postcss']
            },

            bake: {
                files: [
                    '../themes/bookbox_ui/_templates-src/**/*.php'
                ],
                tasks: ['bake']
            }

        },
        
        postcss: {
            options: {
              processors: [
                require('autoprefixer')({browsers: ['last 2 versions', 'ie 10']})
              ]
            },
            dist: {
              src: '../themes/bookbox_ui/css/style.css'
            }
        }
    });

    // load npm modules
    grunt.loadNpmTasks('grunt-bake');
    grunt.loadNpmTasks('grunt-svgstore');
    grunt.loadNpmTasks('grunt-contrib-clean');
    grunt.loadNpmTasks('grunt-contrib-less');
    grunt.loadNpmTasks('grunt-contrib-watch');
    grunt.loadNpmTasks('grunt-postcss');

    grunt.registerTask('default', ['bake', 'svgstore',  'less', 'postcss', 'watch']);
    grunt.registerTask('jenkins', ['bake',  'svgstore',   'less', 'postcss']);
};
